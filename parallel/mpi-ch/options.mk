# $NetBSD: options.mk,v 1.6 2022/08/25 21:46:53 thor Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mpich
PKG_SUPPORTED_OPTIONS=	debug f90
PKG_SUGGESTED_OPTIONS=	f90

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	f90

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-g=debug	# problems
INSTALL_UNSTRIPPED=	yes
.endif

.if !empty(PKG_OPTIONS:Mf90)
USE_LANGUAGES+=		fortran
FFLAGS+=		-fallow-argument-mismatch
CONFIGURE_ARGS+=	--enable-fortran=yes
PLIST.f90=		yes
.else
CONFIGURE_ARGS+=	--enable-fortran=no
.endif
