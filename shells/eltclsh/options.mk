# $NetBSD: options.mk,v 1.2 2019/11/04 21:14:06 rillig Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.eltclsh
PKG_SUPPORTED_OPTIONS=	tk
PKG_SUGGESTED_OPTIONS=	tk

.include "../../mk/bsd.options.mk"

##
## Support TK, i.e. the edit-line wish shell
##
PLIST_VARS+=	tk
.if !empty(PKG_OPTIONS:Mtk)
.include "../../x11/tk/buildlink3.mk"
CONFIGURE_ARGS+=        --with-tk=${BUILDLINK_PREFIX.tk}/lib
PLIST.tk=		yes
.else
CONFIGURE_ARGS+=        --without-tk
.endif
