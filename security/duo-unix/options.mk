# $NetBSD: options.mk,v 1.1 2018/02/16 07:20:56 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.duo-unix
PKG_SUPPORTED_OPTIONS+=	pam
PKG_SUGGESTED_OPTIONS=	pam

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	pam

.if !empty(PKG_OPTIONS:Mpam)
PLIST.pam=		yes
CONFIGURE_ARGS+=	--with-pam=${PREFIX}/lib/security
CONF_FILES_PERMS+=	share/examples/duo-unix/pam_duo.conf    \
			${PKG_SYSCONFDIR}/pam_duo.conf  \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0400
.  include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pam
.endif
