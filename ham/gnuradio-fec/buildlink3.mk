# $NetBSD: buildlink3.mk,v 1.6 2025/02/27 13:49:53 adam Exp $

BUILDLINK_TREE+=	gnuradio-fec

.if !defined(GNURADIO_FEC_BUILDLINK3_MK)
GNURADIO_FEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.10.1.1
BUILDLINK_PKGSRCDIR.gnuradio-fec?=	../../ham/gnuradio-fec

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.endif # GNURADIO_FEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-fec
