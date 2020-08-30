# $NetBSD: buildlink3.mk,v 1.2 2020/08/30 20:51:34 tnn Exp $

BUILDLINK_TREE+=	gnuradio-ctrlport

.if !defined(GNURADIO_CTRLPORT_BUILDLINK3_MK)
GNURADIO_CTRLPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-ctrlport+=	gnuradio-ctrlport>=3.8.1.0
BUILDLINK_ABI_DEPENDS.gnuradio-ctrlport+=	gnuradio-ctrlport>=3.8.1.0
BUILDLINK_PKGSRCDIR.gnuradio-ctrlport?=		../../ham/gnuradio-ctrlport
.endif # GNURADIO_CTRLPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-ctrlport
