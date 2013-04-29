# $NetBSD: options.mk,v 1.1 2013/04/29 07:43:32 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.netcdf-fortran
PKG_SUPPORTED_OPTIONS=	f90

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	f90

.if empty(PKG_OPTIONS:Mf90)
CONFIGURE_ARGS+=	--disable-f90
.else
USE_LANGUAGES+=		fortran
PLIST.f90=		yes
.endif
