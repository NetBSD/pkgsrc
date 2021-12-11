# $NetBSD: buildlink3.mk,v 1.3 2021/12/11 14:57:50 tnn Exp $

BUILDLINK_TREE+=	gnuradio-ctrlport

.if !defined(GNURADIO_CTRLPORT_BUILDLINK3_MK)
GNURADIO_CTRLPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-ctrlport+=	gnuradio-ctrlport>=3.9.4.0
BUILDLINK_ABI_DEPENDS.gnuradio-ctrlport+=	gnuradio-ctrlport>=3.9.4.0
BUILDLINK_PKGSRCDIR.gnuradio-ctrlport?=		../../ham/gnuradio-ctrlport
.endif # GNURADIO_CTRLPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-ctrlport
