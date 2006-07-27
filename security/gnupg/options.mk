# $NetBSD: options.mk,v 1.9 2006/07/27 18:48:03 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnupg
PKG_SUPPORTED_OPTIONS=	curl idea ldap

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH:Mi386}
PKG_SUPPORTED_OPTIONS+=	i586-optimized
.endif

.if ${MACHINE_ARCH:Mm68k}
PKG_SUPPORTED_OPTIONS+=	m68060-optimized
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mi586-optimized)
# use assembler routines optimized for, and only for!, i586
ONLY_FOR_PLATFORM=	*-*-i386
MACHINE_GNU_ARCH=	i586
.endif

.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libcurl
.endif

.if !empty(PKG_OPTIONS:Midea)
# use of IDEA as crypto function
LICENCE=	fee-based-commercial-use
DISTFILES+=	idea.c.gz
SITES.idea.c.gz=ftp://ftp.gnupg.dk/pub/contrib-dk/ \
		http://www.gnupg.dk/contrib-dk/
USE_TOOLS+=	gzcat

pre-configure:
	${GZCAT} ${DISTDIR}/idea.c.gz > ${WRKSRC}/cipher/idea.c
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
PLIST_SUBST+=	OPENLDAP=""
.else
CONFIGURE_ARGS+=--disable-ldap
PLIST_SUBST+=	OPENLDAP="@comment "
.endif

.if !empty(PKG_OPTIONS:Mm68060-optimized)
# be more efficient on M68060 machines
CONFIGURE_ENV+=                M68060=${M68060:Q}
CFLAGS+=                       -m68060
.endif
