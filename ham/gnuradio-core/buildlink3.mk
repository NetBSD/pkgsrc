# $NetBSD: buildlink3.mk,v 1.42 2025/05/18 19:29:32 gdt Exp $

BUILDLINK_TREE+=	gnuradio-core

.if !defined(GNURADIO_CORE_BUILDLINK3_MK)
GNURADIO_CORE_BUILDLINK3_MK:=

# GNU Radio's header files do not compile in c++11 mode, but do in
# c++17 mode.  See Makefile.common for status of reporting upstream.
USE_LANGUAGES+=		c c++
USE_CXX_FEATURES+=	c++17
FORCE_CXX_STD=		c++17

BUILDLINK_API_DEPENDS.gnuradio-core+=	gnuradio-core>=3.10.2
BUILDLINK_ABI_DEPENDS.gnuradio-core+=	gnuradio-core>=3.10.12.0nb4
BUILDLINK_PKGSRCDIR.gnuradio-core?=	../../ham/gnuradio-core

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.endif # GNURADIO_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-core
