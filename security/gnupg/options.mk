# $NetBSD: options.mk,v 1.1.2.1 2005/03/26 10:53:35 snj Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnupg
PKG_SUPPORTED_OPTIONS=	i586-optimized curl idea ldap m68060-optimized

.include "../../mk/bsd.prefs.mk"

# legacy options -- remove after 2005Q1
.if defined(USE_I586) && !empty(USE_I586:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	i586-optimized
.endif

.if defined(M68060) && !empty(M68060:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	m68060-optimized
.endif

.if defined(USE_IDEA) && !empty(USE_IDEA:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	idea
.endif

.if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	ldap
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mi586-optimized)
# use assembler routines optimized for, and only for!, i586
ONLY_FOR_PLATFORM=	*-*-i386
MACHINE_GNU_ARCH=	i586
.endif

.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libcurl
PLIST_SUBST+=	CURL="" NOCURL="@comment "
.else
PLIST_SUBST+=	CURL="@comment " NOCURL=""
.endif

.if !empty(PKG_OPTIONS:Midea)
# use of IDEA as crypto function
LICENCE=	fee-based-commercial-use
DISTFILES+=	idea.c.gz
SITES_idea.c.gz=ftp://ftp.gnupg.dk/pub/contrib-dk/ \
		http://www.gnupg.dk/contrib-dk/

pre-configure:
	${GZCAT} ${DISTDIR}/idea.c.gz > ${WRKSRC}/cipher/idea.c
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap/buildlink3.mk"
PLIST_SUBST+=	OPENLDAP=""
.else
CONFIGURE_ARGS+=--disable-ldap
PLIST_SUBST+=	OPENLDAP="@comment "
.endif

.if !empty(PKG_OPTIONS:Mm68060-optimized)
# be more efficient on M68060 machines
CONFIGURE_ENV+=                M68060=${M68060}
CFLAGS+=                       -m68060
.endif
