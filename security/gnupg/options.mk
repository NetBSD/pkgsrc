# $NetBSD: options.mk,v 1.3 2005/05/15 04:26:24 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnupg
PKG_SUPPORTED_OPTIONS=	i586-optimized curl idea ldap m68060-optimized

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
PKGSRC_USE_TOOLS+=	gzcat

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
