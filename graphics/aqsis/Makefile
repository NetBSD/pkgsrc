# $NetBSD: Makefile,v 1.41 2012/09/15 10:04:46 obache Exp $
#

DISTNAME=		aqsis-1.8.1
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aqsis/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.aqsis.org/
COMMENT=		Renderman clone
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1 AND modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config flex bison

#
# Insists on being built in a separate directory.
#

CONFIGURE_DIRS=		build
CMAKE_ARG_PATH=		..

pre-configure:
	mkdir ${WRKSRC}/build

#
# Something in cmake issues -ldl regardless of whether it's appropriate.
# Kludge around it.
#

# This does not work; it sets CMAKE_DL_LIBS which the cmake documentation
# says is where -ldl comes from, but this does not apparently prevent
# cmake from issuing -ldl.
#CMAKE_ARGS+=		-D CMAKE_DL_LIBS:STRING='${DL_LIBS}'

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

#
# Forcibly reprogram cmake's rpath substitution.
#

BLDIR=		${WRKDIR}/.buildlink/lib

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	post-configure
SUBST_FILES.rpath+=	build/libs/math/cmake_install.cmake
SUBST_FILES.rpath+=	build/libs/util/cmake_install.cmake
SUBST_FILES.rpath+=	build/libs/riutil/cmake_install.cmake
SUBST_FILES.rpath+=	build/libs/slcomp/cmake_install.cmake
SUBST_FILES.rpath+=	build/libs/tex/cmake_install.cmake
SUBST_FILES.rpath+=	build/libs/shadervm/cmake_install.cmake
SUBST_FILES.rpath+=	build/libs/slxargs/cmake_install.cmake
SUBST_FILES.rpath+=	build/libs/ri2rib/cmake_install.cmake
SUBST_FILES.rpath+=	build/libs/core/cmake_install.cmake
SUBST_FILES.rpath+=	build/tools/aqsl/cmake_install.cmake
SUBST_FILES.rpath+=	build/tools/aqsltell/cmake_install.cmake
SUBST_FILES.rpath+=	build/tools/aqsis/cmake_install.cmake
SUBST_FILES.rpath+=	build/tools/miqser/cmake_install.cmake
SUBST_FILES.rpath+=	build/tools/teqser/cmake_install.cmake
SUBST_FILES.rpath+=	build/tools/displays/exr/cmake_install.cmake
SUBST_FILES.rpath+=	build/tools/displays/file/cmake_install.cmake
SUBST_FILES.rpath+=	build/tools/displays/piqsl/cmake_install.cmake
SUBST_FILES.rpath+=	build/tools/displays/sdcBMP/cmake_install.cmake
SUBST_FILES.rpath+=	build/tools/displays/xpm/cmake_install.cmake
SUBST_FILES.rpath+=	build/tools/procedurals/hairgen/cmake_install.cmake
SUBST_SED.rpath=	-e '/OLD_RPATH/s,"::*","${PREFIX}/lib",'
SUBST_SED.rpath+=	-e '/OLD_RPATH/s,${BLDIR},${PREFIX}/lib,'
SUBST_SED.rpath+=	-e '/OLD_RPATH/s,:",",'
SUBST_SED.rpath+=	-e '/NEW_RPATH/s,"${PREFIX}/.*","${PREFIX}/lib",'
SUBST_MESSAGE.rpath=	Fixing broken rpath mangling.

#
# Scripts.
#

REPLACE_PYTHON+=	examples/features/occlusion/occlmap.py

# This script wants to run something called 'hython', which is
# apparently a Python embedding inside something called Houdini,
# which appears to be payware. So let's let it slide.
CHECK_INTERPRETER_SKIP+=	share/aqsis/plugins/houdini/slx2otl.py

# These are all ostensibly bash scripts but I see no bashisms in any of them.
REPLACE_SH+=	examples/features/archives/render.sh
REPLACE_SH+=	examples/features/bake/render.sh
REPLACE_SH+=	examples/features/curves/render.sh
REPLACE_SH+=	examples/features/layeredshaders/render.sh
REPLACE_SH+=	examples/features/levelofdetail/render.sh
REPLACE_SH+=	examples/features/motionblur/render_camera.sh
REPLACE_SH+=	examples/features/motionblur/render_deformation.sh
REPLACE_SH+=	examples/features/multipass/render.sh
REPLACE_SH+=	examples/features/objectinstance/render.sh
REPLACE_SH+=	examples/features/occlusion/render.sh
REPLACE_SH+=	examples/features/pointcloud/render.sh
REPLACE_SH+=	examples/features/shadows/render_autoshadow.sh
REPLACE_SH+=	examples/features/shadows/render_softshadow.sh
REPLACE_SH+=	examples/features/solidmodeling/render.sh
REPLACE_SH+=	examples/features/subdivision/render.sh
REPLACE_SH+=	examples/features/textures/render.sh
REPLACE_SH+=	examples/procedurals/menger/render.sh
REPLACE_SH+=	examples/scenes/fisheye/render.sh
REPLACE_SH+=	examples/scenes/microbe/render.sh
REPLACE_SH+=	examples/scenes/vase/render.sh
REPLACE_SH+=	tools/neqsus/houdini/post.sh
REPLACE_SH+=	distribution/linux/aqsis.sh
REPLACE_SH+=	distribution/linux/aqsl.sh
REPLACE_SH+=	distribution/linux/aqsltell.sh

#
# Handle the config file.
#
# XXX the post-install rule will result in an overwritten config file
# if using a non-DESTDIR build. However, I can't get it to install the
# thing anywhere else; the setting cmake documents that ought to move
# it does not work.
#

PKG_SYSCONFSUBDIR=	aqsis
CONF_FILES+=		share/examples/aqsis/aqsisrc ${PKG_SYSCONFDIR}/aqsisrc
INSTALLATION_DIRS+=	share/examples/aqsis

post-install:
	mv ${DESTDIR}${PREFIX}/etc/aqsis/aqsisrc \
		${DESTDIR}${PREFIX}/share/examples/aqsis/aqsisrc
	rmdir ${DESTDIR}${PREFIX}/etc/aqsis || ${TRUE}
	rmdir ${DESTDIR}${PREFIX}/etc || ${TRUE}

#
# Depends. The package says:
#
# CMake (v2.6.3+)
# Boost (v1.34.1+)
# libtiff.lib (v3.7.1+)
# flex (v2.5.4) (2.5.31 causes problems, see FAQ 2.2)
# bison (v1.35+)
# Qt (v4.6+) - optional, for framebuffer rendering and other GUI components
# libzlib (v1.1.4+)
# libjpeg (v6b+)
# libilmbase (v1.6+)
# OpenEXR - if you want to read and write OpenEXR HDR image files
#
# and in practice it also needs png.
#
# Qt is optional and, for the time being, doesn't work - will need at
# least PLIST additions.
#
# From what I can tell it may react to py-sphinx and/or doxygen by
# installing more docs or other material. Not sure how to beat on
# cmake to make sure this doesn't happen.
#

.include "options.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/ilmbase/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
