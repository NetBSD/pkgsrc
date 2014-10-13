# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 12:51:10 mef Exp $

BUILDLINK_TREE+=	gnuradio-zeromq

.if !defined(GNURADIO_ZEROMQ_BUILDLINK3_MK)
GNURADIO_ZEROMQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-zeromq+=	gnuradio-zeromq>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-zeromq+=	gnuradio-zeromq>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-zeromq?=	../../ham/gnuradio-zeromq
.endif # GNURADIO_ZEROMQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-zeromq
