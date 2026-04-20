# $NetBSD: buildlink3.mk,v 1.19 2026/04/20 18:14:07 adam Exp $

BUILDLINK_TREE+=	libheif

# Make a best effort attempt to bring in an older version of libheif
# on systems with older compilers.  This is done to avoid requiring a
# compiler newer than what the majority of our packages will be built
# with, in order to avoid ABI issues and conflicts with the C++ standard
# library.
#
# On NetBSD, avoid including compiler.mk, in case a mixture of
# GCC versions are being used to build the pkgsrc tree.

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if ${OPSYS_VERSION} < 090000
.    include "../../graphics/libheif-cxx11/buildlink3.mk"
.  endif
.else
.  include "../../mk/compiler.mk"
# XXX: This version logic should not be pasted into bl3 files all over
# XXX: the place; if we're going to do this, there should be
# XXX: infrastructure for it.
.  if ${CC_VERSION:Mgcc-4.*} || ${CC_VERSION:Mgcc-[56].*}
.    include "../../graphics/libheif-cxx11/buildlink3.mk"
.  endif
.endif

# If libheif-cxx11's buildlink3 file has already been included,
# the following section will be ignored.
.if !defined(LIBHEIF_BUILDLINK3_MK)
LIBHEIF_BUILDLINK3_MK:=

USE_CXX_FEATURES+=		c++17

BUILDLINK_API_DEPENDS.libheif+=	libheif>=1.8.0
BUILDLINK_ABI_DEPENDS.libheif+=	libheif>=1.21.2nb1
BUILDLINK_PKGSRCDIR.libheif?=	../../graphics/libheif

.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../multimedia/libde265/buildlink3.mk"
.include "../../multimedia/openh264/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.endif	# LIBHEIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libheif
