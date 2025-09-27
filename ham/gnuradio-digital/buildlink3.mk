# $NetBSD: buildlink3.mk,v 1.10 2025/09/27 09:57:22 wiz Exp $

BUILDLINK_TREE+=	gnuradio-digital

.if !defined(GNURADIO_DIGITAL_BUILDLINK3_MK)
GNURADIO_DIGITAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-digital+=	gnuradio-digital>=3.10.1.1
BUILDLINK_ABI_DEPENDS.gnuradio-digital?=		gnuradio-digital>=3.10.12.0nb6
BUILDLINK_PKGSRCDIR.gnuradio-digital?=		../../ham/gnuradio-digital

.include "../../ham/gnuradio-core/buildlink3.mk"
.endif # GNURADIO_DIGITAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-digital
