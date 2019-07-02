# $NetBSD: Makefile,v 1.45 2019/07/02 13:44:05 gdt Exp $

DISTNAME=	gpsd-3.19
CATEGORIES=	geography
MASTER_SITES=	http://download-mirror.savannah.gnu.org/releases/gpsd/
# will probably switch to https://gitlab.com/gpsd/gpsd/releases

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://gpsd.io/
COMMENT=	GPS information daemon

LICENSE=	modified-bsd

PY_PATCHPLIST=	yes

USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c99 c++

# \todo Separate upstream's build into configure and build.
NO_CONFIGURE=	yes

# Note that gpsd is documented to use ncurses, not curses.
FAKE_NCURSES=	yes
# gpsd uses syncok.  Insist on an implementation that provides it.
USE_CURSES=	syncok

# Documentation depends
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

# \todo Decide if buildlink3 is more appropriate.
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial

CFLAGS.SunOS=	-DLOG_PERROR=0

# Configure phase arguments:
SCONS_ARGS+=	leapfetch=no		# Do not use the net at build time.
SCONS_ARGS+=	target_python=${PYTHONBIN}	# Use our python, not "python".

SUBST_CLASSES+=		pyenv
SUBST_MESSAGE.pyenv=	Fixing path in Python scripts
SUBST_STAGE.pyenv=	pre-build	# We don't configure :-(
SUBST_FILES.pyenv+=	gegps
SUBST_FILES.pyenv+=	gpscat
SUBST_FILES.pyenv+=	gpsfake
SUBST_FILES.pyenv+=	gpsprof
SUBST_FILES.pyenv+=	ubxtool
SUBST_FILES.pyenv+=	xgps
SUBST_FILES.pyenv+=	xgpsspeed
SUBST_FILES.pyenv+=	zerk
SUBST_FILES.pyenv+=	test_misc.py
SUBST_SED.pyenv=	-e 's,/usr/bin/env python.*$$,${PYTHONBIN},'

# \todo: Determine if CC/CXX are needed (e.g, when using other than gcc).
#	CC=${CC:Q} CXX=${CXX:Q}
do-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${SCONSBIN} \
	prefix=${PREFIX} mandir=${PREFIX}/${PKGMANDIR} \
	${SCONS_ARGS} \
	-j${MAKE_JOBS:U1}

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${INSTALL_ENV} ${SCONSBIN} install

do-test:
	cd ${WRKSRC} && \
	${SETENV} ${INSTALL_ENV} ${SCONSBIN} check

# \todo Change to TOOLS or BUILD_DEPENDS after scons support is improved.
.include "../../devel/scons/buildlink3.mk"

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/extension.mk"
# \todo Resolve mk/curses not invoking ncurses builtin processing.
#.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
