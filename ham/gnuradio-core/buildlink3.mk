# $NetBSD: buildlink3.mk,v 1.41 2025/02/27 13:49:50 adam Exp $

BUILDLINK_TREE+=	gnuradio-core

.if !defined(GNURADIO_CORE_BUILDLINK3_MK)
GNURADIO_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-core+=	gnuradio-core>=3.10.2
BUILDLINK_ABI_DEPENDS.gnuradio-core+=	gnuradio-core>=3.10.12.0
BUILDLINK_PKGSRCDIR.gnuradio-core?=	../../ham/gnuradio-core

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.endif # GNURADIO_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-core
