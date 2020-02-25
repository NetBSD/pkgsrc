# $NetBSD: hacks.mk,v 1.2 2020/02/25 04:29:36 brook Exp $

.if !defined(GEGL_HACKS_MK)
GEGL_HACKS_MK=	# defined

### [Wed Dec 12 12:47:17 JST 2012 : pho]
### GEGL tries to use OpenCL in a really weird way. It has (and
### installs!) a local copy of OpenCL headers and then tries to find
### implementation by dlopen'ing "libOpenCL.so". The problem is that
### it fails to compile on Darwin < 10 by trying to include
### non-existent native OpenCL headers too, which is in fact only
### optional.

.if !empty(MACHINE_PLATFORM:Darwin-[0-9].*-*)
PKG_HACKS+=			darwin-opencl

SUBST_CLASSES+=			non-darwin
SUBST_STAGE.non-darwin=		pre-build
SUBST_MESSAGE.non-darwin=	Pretending as if we were not on Darwin.
SUBST_FILES.non-darwin=		gegl/opencl/*.h gegl/opencl/*.c
SUBST_SED.non-darwin+=		-e 's,\#ifdef __APPLE__,\#if 0,g'
SUBST_SED.non-darwin+=		-e 's,\#if defined(__APPLE__),\#if 0,g'

SUBST_CLASSES+=			no-altivec
SUBST_STAGE.no-altivec=		pre-build
SUBST_MESSAGE.no-altivec=	Pretending as if we did not have altivec.
SUBST_FILES.no-altivec=		gegl/opencl/*.h gegl/opencl/*.c
SUBST_SED.no-altivec=		-e 's,\#if defined( __VEC__ ),\#if 0,g'
.endif

.endif
