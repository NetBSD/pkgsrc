# $NetBSD: options.mk,v 1.2 2007/09/25 10:23:22 hira Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tea
PKG_SUPPORTED_OPTIONS=	aspell gtksourceview # enchant antiword
PKG_SUGGESTED_OPTIONS=	# none enabled by default

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maspell)
.include "../../textproc/aspell/buildlink3.mk"
.endif

# --enable-enchant disabled aspell so choose one or the other

.if !empty(PKG_OPTIONS:Mgtksourceview)
.include "../../devel/GConf/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-legacy
.endif
