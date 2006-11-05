# $NetBSD: options.mk,v 1.1.1.1 2006/11/05 14:33:37 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ap-modsecurity2

PKG_SUPPORTED_OPTIONS=	xml
PKG_SUGGESTED_OPTIONS=	xml

.include "../../mk/bsd.options.mk"

###
### Brink in support for libxml2
###
.if !empty(PKG_OPTIONS:Mxml)
.  include "../../textproc/libxml2/buildlink3.mk"
MESSAGE_SRC+=		${WRKDIR}/.MESSAGE_SRC.xml
.endif
