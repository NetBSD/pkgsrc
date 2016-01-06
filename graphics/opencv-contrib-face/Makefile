# $NetBSD: Makefile,v 1.3 2016/01/06 10:46:52 adam Exp $

PKGNAME=	opencv-contrib-face-3.0.0
PKGREVISION=	1
DISTNAME=	opencv_contrib-3.0.0
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Itseez/}
EXTRACT_SUFX=	.zip
GITHUB_PROJECT=	opencv_contrib

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://code.opencv.org/projects/OpenCV/wiki/WikiStart
COMMENT=	OpenCV face recognition contributed module
LICENSE=	modified-bsd

DISTFILES=      ${DEFAULT_DISTFILES} opencv-3.0.0.zip

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

INSTALL_DIRS=	modules/face

WRKSRC=		${WRKDIR}/opencv-3.0.0/

PATCHDIR=	${.CURDIR}/../../graphics/opencv/patches

CMAKE_ARGS+=	-D WITH_FFMPEG=OFF
CMAKE_ARGS+=	-D BUILD_DOCS=OFF

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=		-std=c++11
.endif

OPSYSVARS+=		CMAKE_ARGS
CMAKE_ARGS+=		-DZLIB_ROOT=${BUILDLINK_PREFIX.zlib}
CMAKE_ARGS.SunOS+=	-DENABLE_PRECOMPILED_HEADERS=NO

CMAKE_ARGS+=		-DOPENCV_EXTRA_MODULES_PATH=${WRKDIR}/opencv_contrib-3.0.0/modules
CMAKE_ARGS+=		-DBUILD_opencv_adas=OFF
CMAKE_ARGS+=		-DBUILD_opencv_bgsegm=OFF
CMAKE_ARGS+=		-DBUILD_opencv_bioinspired=OFF
CMAKE_ARGS+=		-DBUILD_opencv_ccalib=OFF
CMAKE_ARGS+=		-DBUILD_opencv_contrib_world=OFF
CMAKE_ARGS+=		-DBUILD_opencv_cvv=OFF
CMAKE_ARGS+=		-DBUILD_opencv_datasets=OFF
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
CMAKE_ARGS+=		-DBUILD_opencv_ml=OFF
CMAKE_ARGS+=		-DBUILD_opencv_photo=OFF
CMAKE_ARGS+=		-DBUILD_opencv_video=OFF
CMAKE_ARGS+=		-DBUILD_opencv_imgcodecs=OFF
CMAKE_ARGS+=		-DBUILD_opencv_videoio=OFF
CMAKE_ARGS+=		-DBUILD_opencv_highgui=OFF
CMAKE_ARGS+=		-DBUILD_opencv_objdetect=OFF
CMAKE_ARGS+=		-DBUILD_opencv_superres=OFF
CMAKE_ARGS+=		-DBUILD_opencv_ts=OFF
CMAKE_ARGS+=		-DBUILD_opencv_features2d=OFF
CMAKE_ARGS+=		-DBUILD_opencv_calib3d=OFF
CMAKE_ARGS+=		-DBUILD_opencv_stitching=OFF
CMAKE_ARGS+=		-DBUILD_opencv_videostab=OFF
CMAKE_ARGS+=		-DBUILD_opencv_python2=OFF

CONFIGURE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
