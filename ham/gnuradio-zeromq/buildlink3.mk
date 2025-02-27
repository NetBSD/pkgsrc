# $NetBSD: buildlink3.mk,v 1.6 2025/02/27 13:49:55 adam Exp $

BUILDLINK_TREE+=	gnuradio-zeromq

.if !defined(GNURADIO_ZEROMQ_BUILDLINK3_MK)
GNURADIO_ZEROMQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-zeromq+=	gnuradio-zeromq>=3.10.1.1
BUILDLINK_PKGSRCDIR.gnuradio-zeromq?=	../../ham/gnuradio-zeromq

.include "../../ham/gnuradio-core/buildlink3.mk"
.endif # GNURADIO_ZEROMQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-zeromq
