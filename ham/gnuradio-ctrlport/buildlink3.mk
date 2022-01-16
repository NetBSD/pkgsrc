# $NetBSD: buildlink3.mk,v 1.4 2022/01/16 18:06:25 tnn Exp $

BUILDLINK_TREE+=	gnuradio-ctrlport

.if !defined(GNURADIO_CTRLPORT_BUILDLINK3_MK)
GNURADIO_CTRLPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-ctrlport+=	gnuradio-ctrlport>=3.10.0.0
BUILDLINK_PKGSRCDIR.gnuradio-ctrlport?=		../../ham/gnuradio-ctrlport
.endif # GNURADIO_CTRLPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-ctrlport
