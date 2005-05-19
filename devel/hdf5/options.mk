# $NetBSD: options.mk,v 1.1 2005/05/19 15:39:04 jwise Exp $

PKG_OPTIONS_VAR=PKG_OPTIONS.hdf5
PKG_SUPPORTED_OPTIONS=	szip
PKG_SUGGESTED_OPTIONS=	szip

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mszip)
CONFIGURE_ARGS+=	--with-szlib
.include "../../archivers/szip/buildlink3.mk"
.endif
