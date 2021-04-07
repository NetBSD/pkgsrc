# $NetBSD: buildlink3.mk,v 1.31 2021/04/07 16:14:07 tnn Exp $

BUILDLINK_TREE+=	gnuradio-core

.if !defined(GNURADIO_CORE_BUILDLINK3_MK)
GNURADIO_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-core+=	gnuradio-core>=3.9.1.0
BUILDLINK_ABI_DEPENDS.gnuradio-core+=	gnuradio-core>=3.9.1.0
BUILDLINK_PKGSRCDIR.gnuradio-core?=	../../ham/gnuradio-core

.include "../../devel/gmp/buildlink3.mk"
.include "../../textproc/log4cpp/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.endif # GNURADIO_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-core
