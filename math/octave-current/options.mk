# $NetBSD: options.mk,v 1.1 2005/04/01 10:15:19 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.octave
PKG_DEFAULT_OPTIONS=	glpk hdf5
PKG_SUPPORTED_OPTIONS=	glpk hdf5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mglpk)
.include "../../math/glpk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-glpk
.endif

.if !empty(PKG_OPTIONS:Mhdf5)
.include "../../devel/hdf5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-hdf5
.endif
