# $NetBSD: buildlink3.mk,v 1.45 2025/09/27 09:57:22 wiz Exp $

BUILDLINK_TREE+=	gnuradio-core

.if !defined(GNURADIO_CORE_BUILDLINK3_MK)
GNURADIO_CORE_BUILDLINK3_MK:=

# GNU Radio's header files do not compile in c++11 mode, but do in
# c++17 mode.  See Makefile.common for status of reporting upstream.
USE_LANGUAGES+=		c c++
USE_CC_FEATURES=	c11
USE_CXX_FEATURES+=	c++17
# This is not really right, because perhaps GNU Radio is ok in c++20
# mode, and some other package might build in that mode, but at least
# gr-osmosdr might build in c++11, which will fail.
FORCE_CXX_STD=		c++17

BUILDLINK_API_DEPENDS.gnuradio-core+=	gnuradio-core>=3.10.2
BUILDLINK_ABI_DEPENDS.gnuradio-core+=	gnuradio-core>=3.10.12.0nb7
BUILDLINK_PKGSRCDIR.gnuradio-core?=	../../ham/gnuradio-core

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.endif # GNURADIO_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-core
