# $NetBSD: buildlink3.mk,v 1.11 2026/08/24 08:42:22 adam Exp $

BUILDLINK_TREE+=	gnuradio-fec

.if !defined(GNURADIO_FEC_BUILDLINK3_MK)
GNURADIO_FEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.10.1.1
BUILDLINK_ABI_DEPENDS.gnuradio-fec?=	gnuradio-fec>=3.10.12.0nb13
BUILDLINK_PKGSRCDIR.gnuradio-fec?=	../../ham/gnuradio-fec

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.endif # GNURADIO_FEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-fec
