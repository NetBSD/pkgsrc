# $NetBSD: options.mk,v 1.2 2013/04/15 21:40:17 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mpich
PKG_SUPPORTED_OPTIONS=	debug mpich-mpd threads
PKG_SUGGESTED_OPTIONS=	threads

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-g=debug	# problems
INSTALL_UNSTRIPPED=	yes
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
PLIST_SRC+=		PLIST.mpd
REPLACE_PYTHON+=	src/pm/mpd/*.py src/pm/mpd/test/*.py
.include "../../lang/python/application.mk"
.endif

PLIST_SRC+=	PLIST
