# $NetBSD: buildlink3.mk,v 1.30 2020/08/30 20:43:46 tnn Exp $

BUILDLINK_TREE+=	gnuradio-core

.if !defined(GNURADIO_CORE_BUILDLINK3_MK)
GNURADIO_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-core+=	gnuradio-core>=3.8.1.0
BUILDLINK_ABI_DEPENDS.gnuradio-core+=	gnuradio-core>=3.8.1.0
BUILDLINK_PKGSRCDIR.gnuradio-core?=	../../ham/gnuradio-core

.include "../../devel/gmp/buildlink3.mk"
.include "../../textproc/log4cpp/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.endif # GNURADIO_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-core
