# $NetBSD: hacks.mk,v 1.4 2023/11/02 21:48:27 wiz Exp $

.if !defined(OPENCV_HACKS_MK)
OPENCV_HACKS_MK=	defined

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/compiler.mk"

# PR toolchain/47051: gcc-4.5.4 breaks opencv on amd64
.if !empty(PKGSRC_COMPILER:Mgcc) && ${CC_VERSION:Mgcc-4.5.4*} && ${MACHINE_PLATFORM:M*-*-x86_64}
PKG_HACKS+=		tree-pre
SUBST_CLASSES+=		opt-hack
SUBST_STAGE.opt-hack=	post-configure
SUBST_MESSAGE.opt-hack=	Working around gcc-4.5.4 bug.
SUBST_FILES.opt-hack=	modules/calib3d/CMakeFiles/opencv_calib3d.dir/build.make
SUBST_SED.opt-hack=	-e '/stereosgbm.cpp.o/s/-o /-fno-tree-pre -o /'
.endif

.endif	# OPENCV_HACKS_MK
