# $NetBSD: options.mk,v 1.2 2005/05/31 10:01:38 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.octave
PKG_SUPPORTED_OPTIONS=	hdf5
PKG_SUGGESTED_OPTIONS=	hdf5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhdf5)
.include "../../devel/hdf5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-hdf5
.endif
