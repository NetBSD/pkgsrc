# $NetBSD: Makefile,v 1.80 2024/05/06 08:40:26 jperkin Exp $

DISTNAME=	gpsd-3.25
PKGREVISION=	8
CATEGORIES=	geography
MASTER_SITES=	http://download-mirror.savannah.gnu.org/releases/gpsd/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://gpsd.io/
COMMENT=	GPS information daemon
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-asciidoctor>=2.0.0:../../textproc/ruby-asciidoctor
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial

USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c99 c++

PY_PATCHPLIST=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	27 38

# Note that gpsd is documented to use ncurses, not curses.
FAKE_NCURSES=	yes
# gpsd uses syncok.  Insist on an implementation that provides it.
USE_CURSES=	syncok

CFLAGS.SunOS=	-DLOG_PERROR=0

## scons arguments
SCONS_BUILD_ARGS+=	prefix=${PREFIX}
SCONS_BUILD_ARGS+=	mandir=${PKGMANDIR}
SCONS_BUILD_ARGS+=	docdir=share/doc/gpsd
# Use the python chosen by pkgsrc, not "/usr/bin/env python"
SCONS_BUILD_ARGS+=	python_shebang=${PYTHONBIN}
SCONS_BUILD_ARGS+=	target_python=${PYTHONBIN}
# Require man pages (the build suceeeds and skips them w/o asciidoctor).
SCONS_BUILD_ARGS+=	manbuild=yes
# Do not use the net at build time.
SCONS_BUILD_ARGS+=	leapfetch=no
# scons is hard to understand, so enable debugging always
#SCONS_BUILD_ARGS+=	--debug=explain,prepare

RCD_SCRIPTS=	gpsd

REPLACE_PYTHON+=	tests/test_misc.py

# \todo Separate upstream's build into configure and build.
do-configure:

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	PLIST_SO=
PLIST_SUBST+=	PLIST_DYLIB=.dylib
.else
PLIST_SUBST+=	PLIST_SO=.so
PLIST_SUBST+=	PLIST_DYLIB=
.endif

.include "../../lang/ruby/rubyversion.mk"
.include "../../devel/scons4/build.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
# \todo Resolve mk/curses not invoking ncurses builtin processing.
# For now, include the ncurses package directly.
.include "../../devel/ncurses/buildlink3.mk"
#.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
