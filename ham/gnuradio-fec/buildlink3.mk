# $NetBSD: buildlink3.mk,v 1.3 2021/12/11 14:57:50 tnn Exp $

BUILDLINK_TREE+=	gnuradio-fec

.if !defined(GNURADIO_FEC_BUILDLINK3_MK)
GNURADIO_FEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.9.4.0
BUILDLINK_ABI_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.9.4.0
BUILDLINK_PKGSRCDIR.gnuradio-fec?=	../../ham/gnuradio-fec
.endif # GNURADIO_FEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-fec
