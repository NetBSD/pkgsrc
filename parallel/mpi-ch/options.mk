# $NetBSD: options.mk,v 1.3 2013/05/10 08:24:57 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mpich
PKG_SUPPORTED_OPTIONS=	debug f90 mpich-mpd threads
PKG_SUGGESTED_OPTIONS=	threads

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	f90 mpd

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-g=debug	# problems
INSTALL_UNSTRIPPED=	yes
.endif

.if !empty(PKG_OPTIONS:Mf90)
USE_LANGUAGES+=		fortran
PLIST.f90=		yes
.else
USE_LANGUAGES+=		fortran77
CONFIGURE_ARGS+=	--disable-fc
.endif

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--with-thread-package=posix # aka pthreads
.include "../../mk/pthread.buildlink3.mk"
.endif

# Allow coexistance of MPICH2 and musicpd by disabling MPICH2 parts:
.if !empty(PKG_OPTIONS:Mmpich-mpd)
CONFLICTS+=		musicpd-[0-9]*	# installs bin/mpd
CONFIGURE_ARGS+=	--with-pm=hydra:mpd:gforker
CONFIGURE_ARGS+=	--with-python=python${PYVERSSUFFIX}
PLIST.mpd=		yes
REPLACE_PYTHON+=	src/pm/mpd/*.py src/pm/mpd/test/*.py
.include "../../lang/python/application.mk"
.endif
