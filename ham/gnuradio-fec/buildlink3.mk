# $NetBSD: buildlink3.mk,v 1.7 2025/05/18 19:31:20 gdt Exp $

BUILDLINK_TREE+=	gnuradio-fec

.if !defined(GNURADIO_FEC_BUILDLINK3_MK)
GNURADIO_FEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.10.1.1
BUILDLINK_ABI_DEPENDS.gnuradio-fec?=	gnuradio-fec>=3.10.12.0nb3
BUILDLINK_PKGSRCDIR.gnuradio-fec?=	../../ham/gnuradio-fec

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.endif # GNURADIO_FEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-fec
