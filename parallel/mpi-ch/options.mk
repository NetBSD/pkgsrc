# $NetBSD: options.mk,v 1.4 2017/04/29 18:18:52 adam Exp $

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
#USE_LANGUAGES+=		fortran77
#CONFIGURE_ARGS+=	--enable-fortran=f77
CONFIGURE_ARGS+=	--enable-fortran=no
.endif
