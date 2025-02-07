# $NetBSD: Makefile,v 1.44 2025/02/07 21:57:08 wiz Exp $

# can't use ninja because we only want to install parts of it
CMAKE_GENERATOR=	make
INSTALL_DIRS=		modules/face modules/plot modules/tracking

.include "../../graphics/opencv/Makefile.common"

DISTNAME=	opencv_contrib-${OPENCV_VERSION}
PKGNAME=	${DISTNAME:S/_contrib/-contrib-face/}
GITHUB_PROJECT=	opencv_contrib

MAINTAINER=	markd@NetBSD.org
COMMENT=	OpenCV face recognition contributed module

DISTFILES=	${DEFAULT_DISTFILES} opencv-${PKGVERSION_NOREV}${EXTRACT_SUFX} opencv-${PKGVERSION_NOREV}_face_landmark_model.dat
# use the hash from modules/face/CMakeLists.txt
SITES.opencv-4.11.0_face_landmark_model.dat=	-https://raw.githubusercontent.com/opencv/opencv_3rdparty/8afa57abc8229d611c4937165d20e2a2d9fc5a12/face_landmark_model.dat

WRKSRC=		${WRKDIR}/opencv-${PKGVERSION_NOREV}

post-extract:
	${CP} ${WRKDIR}/opencv-${PKGVERSION_NOREV}_face_landmark_model.dat ${WRKDIR}/opencv_contrib-${PKGVERSION_NOREV}/modules/face/face_landmark_model.dat

CMAKE_CONFIGURE_ARGS+=		-DBUILD_DOCS=OFF
CMAKE_CONFIGURE_ARGS+=		-DWITH_FFMPEG=OFF
CMAKE_CONFIGURE_ARGS+=		-DWITH_JASPER=OFF

CMAKE_CONFIGURE_ARGS+=		-DOPENCV_EXTRA_MODULES_PATH=${WRKDIR}/${DISTNAME}/modules
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_adas=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_aruco=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_bgsegm=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_bioinspired=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_ccalib=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_contrib_world=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_cvv=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_datasets=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_dnn_objdetect=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_dpm=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_fuzzy=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_hdf=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_hfs=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_imgcodecs=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_img_hash=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_intensity_transforms=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_latentsvm=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_line_descriptor=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_matlab=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_optflow=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_phase_unwrapping=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_rapid=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_reg=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_rgbd=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_saliency=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_shape=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_signal=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_stereo=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_structured_light=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_surface_matching=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_text=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_xfeatures2d=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_ximgproc=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_xobjdetect=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_xphoto=OFF

CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_dnn=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_highgui=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_ml=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_python2=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_python3=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_stitching=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_superres=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_ts=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_videoio=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_videostab=OFF

# needed by face
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_objdetect=ON
# needed by objdetect
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_calib3d=ON
# needed by calib3d
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_features2d=ON
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_flann=ON
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_imgproc=ON
# needed by flann and objdetect
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_core=ON

# needed by tracking
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_video=ON

BUILDLINK_API_DEPENDS.opencv+=	opencv>=${PKGVERSION_NOREV}
.include "../../graphics/opencv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
