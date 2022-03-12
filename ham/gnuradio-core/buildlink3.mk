# $NetBSD: buildlink3.mk,v 1.35 2022/03/12 23:04:45 tnn Exp $

BUILDLINK_TREE+=	gnuradio-core

.if !defined(GNURADIO_CORE_BUILDLINK3_MK)
GNURADIO_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-core+=	gnuradio-core>=3.10.1.1
BUILDLINK_PKGSRCDIR.gnuradio-core?=	../../ham/gnuradio-core

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.endif # GNURADIO_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-core
