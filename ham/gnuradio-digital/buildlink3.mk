# $NetBSD: buildlink3.mk,v 1.6 2022/03/12 23:04:45 tnn Exp $

BUILDLINK_TREE+=	gnuradio-digital

.if !defined(GNURADIO_DIGITAL_BUILDLINK3_MK)
GNURADIO_DIGITAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-digital+=	gnuradio-digital>=3.10.1.1
BUILDLINK_PKGSRCDIR.gnuradio-digital?=		../../ham/gnuradio-digital
.endif # GNURADIO_DIGITAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-digital
