# $NetBSD: options.mk,v 1.18 2026/01/28 09:28:12 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnupg
PKG_SUPPORTED_OPTIONS=	curl ldap

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == i386
PKG_SUPPORTED_OPTIONS+=	i586-optimized
.endif

.if ${MACHINE_ARCH} == m68k
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

PLIST_VARS+=		ldap
.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
PLIST.ldap=		yes
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if !empty(PKG_OPTIONS:Mm68060-optimized)
# be more efficient on M68060 machines
CONFIGURE_ENV+=		M68060=${M68060:Q}
CFLAGS+=		-m68060
.endif
