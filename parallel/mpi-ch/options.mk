# $NetBSD: options.mk,v 1.5 2017/06/20 17:24:06 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mpich
PKG_SUPPORTED_OPTIONS=	debug f90

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	f90

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-g=debug	# problems
INSTALL_UNSTRIPPED=	yes
.endif

.if !empty(PKG_OPTIONS:Mf90)
USE_LANGUAGES+=		fortran
CONFIGURE_ARGS+=	--enable-fortran=yes
PLIST.f90=		yes
.else
CONFIGURE_ARGS+=	--enable-fortran=no
.endif
