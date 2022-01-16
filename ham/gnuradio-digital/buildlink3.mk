# $NetBSD: buildlink3.mk,v 1.5 2022/01/16 18:06:26 tnn Exp $

BUILDLINK_TREE+=	gnuradio-digital

.if !defined(GNURADIO_DIGITAL_BUILDLINK3_MK)
GNURADIO_DIGITAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-digital+=	gnuradio-digital>=3.10.0.0
BUILDLINK_PKGSRCDIR.gnuradio-digital?=		../../ham/gnuradio-digital
.endif # GNURADIO_DIGITAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-digital
