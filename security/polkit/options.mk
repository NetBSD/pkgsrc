# $NetBSD: options.mk,v 1.5 2022/06/07 18:03:55 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.polkit
PKG_SUPPORTED_OPTIONS=	pam
PKG_SUGGESTED_OPTIONS=	pam

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	pam

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-authfw=pam
CONFIGURE_ARGS+=	--with-pam-module-dir=${PREFIX}/lib/security
PLIST.pam=	yes
.  if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-pam-include=system
.  endif
MAKE_DIRS+=	/etc/pam.d
CONF_FILES+=	${PREFIX}/share/examples/pam.d/polkit-1 \
		/etc/pam.d/polkit-1
.else
CONFIGURE_ARGS+=	--with-authfw=shadow
CONFIGURE_ARGS+=	--disable-pam-module
.endif
