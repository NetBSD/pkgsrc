# $NetBSD: buildlink3.mk,v 1.3 2020/08/30 20:53:11 tnn Exp $

BUILDLINK_TREE+=	gnuradio-digital

.if !defined(GNURADIO_DIGITAL_BUILDLINK3_MK)
GNURADIO_DIGITAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-digital+=	gnuradio-digital>=3.8.1.0
BUILDLINK_ABI_DEPENDS.gnuradio-digital+=	gnuradio-digital>=3.8.1.0
BUILDLINK_PKGSRCDIR.gnuradio-digital?=		../../ham/gnuradio-digital
.endif # GNURADIO_DIGITAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-digital
