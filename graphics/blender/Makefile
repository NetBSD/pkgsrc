# $NetBSD: Makefile,v 1.120 2016/03/05 11:28:36 jperkin Exp $

DISTNAME=	blender-2.76b
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://download.blender.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.blender.org/
COMMENT=	Fully integrated 3D graphics creation suite
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake sed
USE_LANGUAGES=		c c++

PYTHON_VERSIONS_ACCEPTED=	35 34 33
GCC_REQD+=	4.7

BUILD_DEPENDS+=		scons-[0-9]*:../../devel/scons

.include "options.mk"

INSTALLATION_DIRS=	bin share/blender

.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
PYLDFLAGS+=		'-lexecinfo',
.endif
PYLDFLAGS+=		'${COMPILER_RPATH_FLAG}${PREFIX}/lib', \
			'${COMPILER_RPATH_FLAG}${X11BASE}/lib'

# To pass LDFLAGS to compiler/linker
SUBST_CLASSES+=		ldflags
SUBST_STAGE.ldflags=	pre-configure
SUBST_MESSAGE.ldflags=	Setting LDFLAGS
SUBST_FILES.ldflags+=	build_files/scons/config/*-config.py
SUBST_VARS.ldflags+=	PYLDFLAGS

SCONS_ARGS+=	WITH_BF_JACK=False
SCONS_ARGS+=	WITH_BF_OPENAL=False
SCONS_ARGS+=	WITH_BF_SNDFILE=False
SCONS_ARGS+=	WITH_BF_FFMPEG=False
SCONS_ARGS+=	WITH_BF_3DMOUSE=False

SCONS_ARGS+=	BF_PYTHON=${PREFIX}
#SCONS_ARGS+=	BF_PYTHON_INC=${PREFIX}/include/python${PYVERSSUFFIX}
SCONS_ARGS+=	BF_PYTHON_ABI_FLAGS=''
SCONS_ARGS+=	BF_PYTHON_VERSION=${PYVERSSUFFIX}
SCONS_ARGS+=	BF_SDL=${BUILDLINK_PREFIX.SDL}
SCONS_ARGS+=	BF_OPENEXR=${BUILDLINK_PREFIX.openexr}
SCONS_ARGS+=	BF_JPEG=${BUILDLINK_PREFIX.jpeg}
SCONS_ARGS+=	BF_PNG=${BUILDLINK_PREFIX.png}
SCONS_ARGS+=	BF_TIFF=${BUILDLINK_PREFIX.tiff}
SCONS_ARGS+=	BF_GETTEXT=${BUILDLINK_PREFIX.gettext-tools}
SCONS_ARGS+=	BF_FREETYPE=${BUILDLINK_PREFIX.freetype2}
SCONS_ARGS+=	BF_OPENJPEG=${BUILDLINK_PREFIX.openjpeg15}
SCONS_ARGS+=	BF_OPENJPEG_INC=${BUILDLINK_PREFIX.openjpeg15}/include/openjpeg-1.5
SCONS_ARGS+=	BF_OPENGL=${BUILDLINK_PREFIX.Mesa}
SCONS_ARGS+=	BF_PCRE=${BUILDLINK_PREFIX.pcre}
#SCONS_ARGS+=	BF_FFMPEG=${BUILDLINK_PREFIX.ffmpeg010}
#SCONS_ARGS+=	BF_FFMPEG_INC=${BUILDLINK_PREFIX.ffmpeg010}/include/ffmpeg010
#SCONS_ARGS+=	BF_FFMPEG_LIBPATH='${BUILDLINK_PREFIX.ffmpeg010}/lib/ffmpeg010'
SCONS_ARGS+=	BF_FFTW3=${BUILDLINK_PREFIX.fftw}
SCONS_ARGS+=	BF_INSTALLDIR=${DESTDIR}${PREFIX}/share/blender

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=	BLENDERVER=${PKGVERSION_NOREV:C/[a-z]//}

.if !empty(MACHINE_PLATFORM:MNetBSD-7.*)
PLIST_SUBST+=	NETBSDVER=netbsd7
.else
PLIST_SUBST+=	NETBSDVER=netbsd6
.endif

PLIST_VARS+=	py34 py35

post-patch:
	cd ${WRKSRC}/build_files/scons/config/; ln netbsd6-config.py netbsd7-config.py

# I cannot separate build and install...
do-build:

# build is done in install phase.
do-install:
	cd ${WRKSRC:Q} && ${PKGSRC_SETENV} ${MAKE_ENV}			\
		${LOCALBASE}/bin/scons ${SCONS_ARGS} ${_MAKE_JOBS}

CHECK_INTERPRETER_SKIP=	share/blender/${DISTNAME:S/blender-//:C/[a-z]//}/scripts/*.py share/blender/${DISTNAME:S/blender-//:C/[a-z]//}datafiles/*.py \
			share/blender/${DISTNAME:S/blender-//:C/[a-z]//}/python/lib/python3.3/venv/scripts/posix/pydoc

REPLACE_PYTHON+=	release/bin/blender-thumbnailer.py
REPLACE_PYTHON+=	intern/cycles/kernel/SConscript

post-install:
	${LN} -sf ${PREFIX}/share/blender/blender \
		${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openimageio/buildlink3.mk"
.include "../../graphics/openjpeg15/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
#.include "../../multimedia/ffmpeg010/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../lang/python/application.mk"

.if ${PYVERSSUFFIX} == "3.4"
PLIST.py34=	yes
.elif ${PYVERSSUFFIX} == "3.5"
PLIST.py35=	yes
.endif

.include "../../mk/bsd.pkg.mk"
