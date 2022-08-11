# $NetBSD: Makefile,v 1.66 2022/08/11 05:08:37 gutteridge Exp $

DISTNAME=	gpsd-3.24
PKGREVISION=	3
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

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial

PYTHON_VERSIONS_INCOMPATIBLE=	27

CFLAGS.SunOS=	-DLOG_PERROR=0

## scons arguments
SCONS_ARGS+=	prefix=${PREFIX}
SCONS_ARGS+=	mandir=${PKGMANDIR}
SCONS_ARGS+=	docdir=share/doc/gpsd
# Use the python chosen by pkgsrc, not "/usr/bin/env python"
SCONS_ARGS+=	python_shebang=${PYTHONBIN}
SCONS_ARGS+=	target_python=${PYTHONBIN}
# Require man pages (the build suceeeds and skips them w/o asciidoctor).
SCONS_ARGS+=	manbuild=yes
# Do not use the net at build time.
SCONS_ARGS+=	leapfetch=no
# scons is hard to understand, so enable debugging always
SCONS_ARGS+=	--debug=explain,prepare

RCD_SCRIPTS=	gpsd

SUBST_CLASSES+=		pyenv
SUBST_MESSAGE.pyenv=	Fixing Python path in test script
# We would choose post-configure, but gpsd's build system blurs
# configure and build.
SUBST_STAGE.pyenv=	pre-build
SUBST_FILES.pyenv+=	tests/test_misc.py
SUBST_SED.pyenv=	-e 's,/usr/bin/env python.*$$,${PYTHONBIN},'

# \todo: Determine if CC/CXX are needed (e.g, when using other than gcc).
#	CC=${CC:Q} CXX=${CXX:Q}
do-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${SCONSBIN} \
	${SCONS_ARGS} \
	-j${MAKE_JOBS:U1}

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${SCONSBIN} \
	${SCONS_ARGS} \
	install

do-test:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${SCONSBIN} \
	${SCONS_ARGS} \
	check

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	PLIST_SO=
PLIST_SUBST+=	PLIST_DYLIB=.dylib
.else
PLIST_SUBST+=	PLIST_SO=.so
PLIST_SUBST+=	PLIST_DYLIB=
.endif

.include "../../lang/ruby/rubyversion.mk"
TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-asciidoctor>=2.0.0:../../textproc/ruby-asciidoctor

# \todo Change to TOOLS or BUILD_DEPENDS after scons support is improved.
.include "../../devel/scons/buildlink3.mk"

.include "../../devel/libusb1/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gtk3/buildlink3.mk"
# \todo Resolve mk/curses not invoking ncurses builtin processing.
# For now, include the ncurses package directly.
.include "../../devel/ncurses/buildlink3.mk"
#.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
