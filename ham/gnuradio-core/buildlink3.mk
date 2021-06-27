# $NetBSD: buildlink3.mk,v 1.32 2021/06/27 08:08:59 tnn Exp $

BUILDLINK_TREE+=	gnuradio-core

.if !defined(GNURADIO_CORE_BUILDLINK3_MK)
GNURADIO_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-core+=	gnuradio-core>=3.9.2.0
BUILDLINK_ABI_DEPENDS.gnuradio-core+=	gnuradio-core>=3.9.2.0
BUILDLINK_PKGSRCDIR.gnuradio-core?=	../../ham/gnuradio-core

.include "../../devel/gmp/buildlink3.mk"
.include "../../textproc/log4cpp/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.endif # GNURADIO_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-core
