# $NetBSD: Makefile,v 1.100 2013/12/27 01:59:42 dholland Exp $

DISTNAME=	blender-2.68a
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://download.blender.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.blender.org/
COMMENT=	Fully integrated 3D graphics creation suite
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

PYTHON_VERSIONS_ACCEPTED=	33

BUILD_DEPENDS+=		scons-[0-9]*:../../devel/scons

FIND_PREFIX:=		SCONSDIR=scons
.include "../../mk/find-prefix.mk"

.include "options.mk"

INSTALLATION_DIRS=	bin share/blender

.if ${OPSYS} == "NetBSD"
# This doesn't seem right...
.if !empty(OS_VERSION:M6.99.*) || !empty(OS_VERSION:M7.*)
LDFLAGS+=	-lexecinfo
.endif
.endif

# To pass LDFLAGS to compiler/linker
MYLDFLAGS=	`printf "'%s'," ${LDFLAGS} | sed -e 's:,$$::'`
pre-configure:
	${CP} -f ${WRKSRC}/user-config.py ${WRKSRC}/user-config.py.1
	${SED} \
		-e "s|@MYLDFLAGS@|${MYLDFLAGS}|g" \
		< ${WRKSRC}/user-config.py.1 > ${WRKSRC}/user-config.py
	${RM} -f ${WRKSRC}/user-config.py.1

SCONS_ARGS+=	WITH_BF_JACK=False
SCONS_ARGS+=	WITH_BF_OPENAL=False
SCONS_ARGS+=	WITH_BF_SNDFILE=False
SCONS_ARGS+=	WITH_BF_FFMPEG=False

SCONS_ARGS+=	BF_PYTHON=${PREFIX}
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

# I cannot separate build and install...
do-build:

# build is done in install phase.
do-install:
	cd ${WRKSRC} && \
		${SCONSDIR}/bin/scons ${SCONS_ARGS}

CHECK_INTERPRETER_SKIP=	share/blender/${DISTNAME:S/blender-//:C/[a-z]//}/scripts/*.py share/blender/${DISTNAME:S/blender-//:C/[a-z]//}datafiles/*.py \
			share/blender/${DISTNAME:S/blender-//:C/[a-z]//}/python/lib/python3.3/venv/scripts/posix/pydoc

post-install:
	${LN} -sf ${PREFIX}/share/blender/blender \
		${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
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

.include "../../mk/bsd.pkg.mk"
