# $NetBSD: options.mk,v 1.2 2020/03/26 11:31:48 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.netcdf-fortran
PKG_SUPPORTED_OPTIONS=	f90

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	f90

.if !empty(PKG_OPTIONS:Mf90)
USE_LANGUAGES+=		fortran
PLIST.f90=		yes
.else
CONFIGURE_ARGS+=	--disable-f90
.endif
