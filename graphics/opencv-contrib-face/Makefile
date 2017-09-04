# $NetBSD: Makefile,v 1.11 2017/09/04 15:23:49 fhajny Exp $

DISTNAME=	opencv_contrib-3.3.0
PKGNAME=	${DISTNAME:S/_contrib/-contrib-face/}
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Itseez/}
EXTRACT_SUFX=	.zip
GITHUB_PROJECT=	opencv_contrib

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://code.opencv.org/projects/OpenCV/wiki/WikiStart
COMMENT=	OpenCV face recognition contributed module
LICENSE=	modified-bsd

DISTFILES=	${DEFAULT_DISTFILES} opencv-${PKGVERSION_NOREV}.zip

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

# This is ugly, but we shouldn't let optional code download
# at configure time. Especially when it needs to be patched
# because of lame coding.
SUBST_CLASSES+=		tnn
SUBST_FILES.tnn=	${WRKDIR}/${DISTNAME}/modules/dnn_modern/CMakeLists.txt
SUBST_MESSAGE.tnn=	Disabling build-time fetch
SUBST_STAGE.tnn=	pre-configure
SUBST_SED.tnn=		-e 's,3.2,999,'

INSTALL_DIRS=	build/modules/face

WRKSRC=		${WRKDIR}/opencv-${PKGVERSION_NOREV}/

PATCHDIR=	${.CURDIR}/../../graphics/opencv/patches

CMAKE_ARGS+=	-D WITH_FFMPEG=OFF
CMAKE_ARGS+=	-D BUILD_DOCS=OFF

# jasper uses SIZE_MAX and friends in its headers.
CXXFLAGS+=		-D__STDC_LIMIT_MACROS

CMAKE_ARGS+=		-DZLIB_ROOT=${BUILDLINK_PREFIX.zlib}
CMAKE_ARGS.SunOS+=	-DENABLE_PRECOMPILED_HEADERS=NO
CMAKE_ARGS+=		-DWITH_EIGEN=NO

CMAKE_ARGS+=		-DOPENCV_EXTRA_MODULES_PATH=${WRKDIR}/${DISTNAME}/modules
CMAKE_ARGS+=		-DBUILD_opencv_adas=OFF
CMAKE_ARGS+=		-DBUILD_opencv_bgsegm=OFF
CMAKE_ARGS+=		-DBUILD_opencv_bioinspired=OFF
CMAKE_ARGS+=		-DBUILD_opencv_ccalib=OFF
CMAKE_ARGS+=		-DBUILD_opencv_contrib_world=OFF
CMAKE_ARGS+=		-DBUILD_opencv_cvv=OFF
CMAKE_ARGS+=		-DBUILD_opencv_datasets=OFF
CMAKE_ARGS+=		-DBUILD_opencv_hdf=OFF
CMAKE_ARGS+=		-DBUILD_opencv_latentsvm=OFF
CMAKE_ARGS+=		-DBUILD_opencv_line_descriptor=OFF
CMAKE_ARGS+=		-DBUILD_opencv_matlab=OFF
CMAKE_ARGS+=		-DBUILD_opencv_optflow=OFF
CMAKE_ARGS+=		-DBUILD_opencv_reg=OFF
CMAKE_ARGS+=		-DBUILD_opencv_rgbd=OFF
CMAKE_ARGS+=		-DBUILD_opencv_saliency=OFF
CMAKE_ARGS+=		-DBUILD_opencv_surface_matching=OFF
CMAKE_ARGS+=		-DBUILD_opencv_text=OFF
CMAKE_ARGS+=		-DBUILD_opencv_tracking=OFF
CMAKE_ARGS+=		-DBUILD_opencv_xfeatures2d=OFF
CMAKE_ARGS+=		-DBUILD_opencv_ximgproc=OFF
CMAKE_ARGS+=		-DBUILD_opencv_xobjdetect=OFF
CMAKE_ARGS+=		-DBUILD_opencv_xphoto=OFF

CMAKE_ARGS+=		-DBUILD_opencv_flann=OFF
CMAKE_ARGS+=		-DBUILD_opencv_photo=OFF
CMAKE_ARGS+=		-DBUILD_opencv_video=OFF
CMAKE_ARGS+=		-DBUILD_opencv_videoio=OFF
CMAKE_ARGS+=		-DBUILD_opencv_highgui=OFF
CMAKE_ARGS+=		-DBUILD_opencv_superres=OFF
CMAKE_ARGS+=		-DBUILD_opencv_ts=OFF
CMAKE_ARGS+=		-DBUILD_opencv_features2d=OFF
CMAKE_ARGS+=		-DBUILD_opencv_calib3d=OFF
CMAKE_ARGS+=		-DBUILD_opencv_stitching=OFF
CMAKE_ARGS+=		-DBUILD_opencv_videostab=OFF
CMAKE_ARGS+=		-DBUILD_opencv_python2=OFF

CONFIGURE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

CONFIGURE_DIRS+=	build
CMAKE_ARG_PATH=		${WRKSRC}

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
BUILDLINK_API_DEPENDS.opencv+=	opencv>=${PKGVERSION_NOREV}
.include "../../graphics/opencv/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
