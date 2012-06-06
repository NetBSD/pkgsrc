# $NetBSD: options.mk,v 1.5 2012/06/06 23:14:10 asau Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.octave
PKG_SUPPORTED_OPTIONS=	glpk graphicsmagick hdf5 qhull
PKG_SUGGESTED_OPTIONS=	glpk hdf5 qhull

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mglpk)
.include "../../math/glpk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-glpk
.endif

.if !empty(PKG_OPTIONS:Mgraphicsmagick)
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.else
CONFIGURE_ENV+=		ac_cv_prog_MAGICK_CONFIG=no
.endif

.if !empty(PKG_OPTIONS:Mhdf5)
.include "../../devel/hdf5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-hdf5
.endif

.if !empty(PKG_OPTIONS:Mqhull)
.include "../../math/qhull/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-qhull
.endif
