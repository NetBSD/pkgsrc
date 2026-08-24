# $NetBSD: buildlink3.mk,v 1.12 2026/08/24 08:42:22 adam Exp $

BUILDLINK_TREE+=	gnuradio-digital

.if !defined(GNURADIO_DIGITAL_BUILDLINK3_MK)
GNURADIO_DIGITAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-digital+=	gnuradio-digital>=3.10.1.1
BUILDLINK_ABI_DEPENDS.gnuradio-digital?=		gnuradio-digital>=3.10.12.0nb13
BUILDLINK_PKGSRCDIR.gnuradio-digital?=		../../ham/gnuradio-digital

.include "../../ham/gnuradio-core/buildlink3.mk"
.endif # GNURADIO_DIGITAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-digital
