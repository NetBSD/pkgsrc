# $NetBSD: Makefile,v 1.39 2024/05/29 16:35:18 adam Exp $

PKGREVISION= 3
.include "../../graphics/opencv/Makefile.common"

DISTNAME=	opencv_contrib-${OPENCV_VERSION}
PKGNAME=	${DISTNAME:S/_contrib/-contrib-face/}
GITHUB_PROJECT=	opencv_contrib

MAINTAINER=	markd@NetBSD.org
COMMENT=	OpenCV face recognition contributed module

DISTFILES=	${DEFAULT_DISTFILES} opencv-${PKGVERSION_NOREV}${EXTRACT_SUFX}

INSTALL_DIRS=	build/modules/face build/modules/plot build/modules/tracking

WRKSRC=		${WRKDIR}/opencv-${PKGVERSION_NOREV}

CMAKE_ARGS+=	-DBUILD_DOCS=OFF
CMAKE_ARGS+=	-DWITH_FFMPEG=OFF
CMAKE_ARGS+=	-DWITH_JASPER=OFF

CMAKE_ARGS+=		-DOPENCV_EXTRA_MODULES_PATH=${WRKDIR}/${DISTNAME}/modules
CMAKE_ARGS+=		-DBUILD_opencv_adas=OFF
CMAKE_ARGS+=		-DBUILD_opencv_bgsegm=OFF
CMAKE_ARGS+=		-DBUILD_opencv_bioinspired=OFF
CMAKE_ARGS+=		-DBUILD_opencv_ccalib=OFF
CMAKE_ARGS+=		-DBUILD_opencv_contrib_world=OFF
CMAKE_ARGS+=		-DBUILD_opencv_cvv=OFF
CMAKE_ARGS+=		-DBUILD_opencv_datasets=OFF
CMAKE_ARGS+=		-DBUILD_opencv_dnn_objdetect=OFF
CMAKE_ARGS+=		-DBUILD_opencv_hdf=OFF
CMAKE_ARGS+=		-DBUILD_opencv_hfs=OFF
CMAKE_ARGS+=		-DBUILD_opencv_img_hash=OFF
CMAKE_ARGS+=		-DBUILD_opencv_latentsvm=OFF
CMAKE_ARGS+=		-DBUILD_opencv_line_descriptor=OFF
CMAKE_ARGS+=		-DBUILD_opencv_matlab=OFF
CMAKE_ARGS+=		-DBUILD_opencv_optflow=OFF
CMAKE_ARGS+=		-DBUILD_opencv_reg=OFF
CMAKE_ARGS+=		-DBUILD_opencv_rgbd=OFF
CMAKE_ARGS+=		-DBUILD_opencv_saliency=OFF
CMAKE_ARGS+=		-DBUILD_opencv_surface_matching=OFF
CMAKE_ARGS+=		-DBUILD_opencv_text=OFF
CMAKE_ARGS+=		-DBUILD_opencv_xfeatures2d=OFF
CMAKE_ARGS+=		-DBUILD_opencv_ximgproc=OFF
CMAKE_ARGS+=		-DBUILD_opencv_xobjdetect=OFF
CMAKE_ARGS+=		-DBUILD_opencv_xphoto=OFF

CMAKE_ARGS+=		-DBUILD_opencv_dnn=OFF
CMAKE_ARGS+=		-DBUILD_opencv_flann=OFF
CMAKE_ARGS+=		-DBUILD_opencv_highgui=OFF
CMAKE_ARGS+=		-DBUILD_opencv_ml=OFF
CMAKE_ARGS+=		-DBUILD_opencv_python2=OFF
CMAKE_ARGS+=		-DBUILD_opencv_python3=OFF
CMAKE_ARGS+=		-DBUILD_opencv_stitching=OFF
CMAKE_ARGS+=		-DBUILD_opencv_superres=OFF
CMAKE_ARGS+=		-DBUILD_opencv_ts=OFF
CMAKE_ARGS+=		-DBUILD_opencv_videoio=OFF
CMAKE_ARGS+=		-DBUILD_opencv_videostab=OFF

# At least as of 3.4.6, these are dependencies of the 'face' module
# and need to be built and installed ('photo' and 'video' are
# part of the main opencv package already
#CMAKE_ARGS+=		-DBUILD_opencv_calib3d=OFF
#CMAKE_ARGS+=		-DBUILD_opencv_features2d=OFF
#CMAKE_ARGS+=		-DBUILD_opencv_photo=OFF
#CMAKE_ARGS+=		-DBUILD_opencv_plot=OFF
#CMAKE_ARGS+=		-DBUILD_opencv_tracking=OFF
#CMAKE_ARGS+=		-DBUILD_opencv_video=OFF

# XXX: INSTALL_DIRS currently do not work as desired in cmake/build.mk.
USE_CMAKE=	yes
pre-configure:
	${MKDIR} ${WRKSRC}/build

BUILDLINK_API_DEPENDS.opencv+=	opencv>=${PKGVERSION_NOREV}
.include "../../graphics/opencv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
