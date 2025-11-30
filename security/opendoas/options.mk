# $NetBSD: options.mk,v 1.3 2025/11/30 16:57:34 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opendoas

PKG_SUPPORTED_OPTIONS+=	pam persist
.if exists(/usr/include/security/pam_appl.h)
PKG_SUGGESTED_OPTIONS+=	pam
.endif

PLIST_VARS+=	pam-conf

.include "../../mk/bsd.options.mk"

##
## Enable credential caching.
##
.if !empty(PKG_OPTIONS:Mpersist)
CONFIGURE_ARGS+=	--with-timestamp
.endif

###
### Enable PAM auth support.
###
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
.  if ${OPSYS} == "Linux" || ${OPSYS} == "Darwin"
PLIST.pam-conf= yes
REQD_FILES=     ${EGDIR}/doas /etc/pam.d/doas
.  endif
.else
CONFIGURE_ARGS+=        --without-pam
.endif
