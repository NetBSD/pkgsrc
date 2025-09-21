# $NetBSD: buildlink3.mk,v 1.8 2025/09/21 18:15:08 wiz Exp $

BUILDLINK_TREE+=	gnuradio-zeromq

.if !defined(GNURADIO_ZEROMQ_BUILDLINK3_MK)
GNURADIO_ZEROMQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-zeromq+=	gnuradio-zeromq>=3.10.1.1
BUILDLINK_ABI_DEPENDS.gnuradio-zeromq?=	gnuradio-zeromq>=3.10.12.0nb5
BUILDLINK_PKGSRCDIR.gnuradio-zeromq?=	../../ham/gnuradio-zeromq

.include "../../ham/gnuradio-core/buildlink3.mk"
.endif # GNURADIO_ZEROMQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-zeromq
