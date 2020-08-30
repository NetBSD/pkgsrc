# $NetBSD: buildlink3.mk,v 1.2 2020/08/30 21:01:28 tnn Exp $

BUILDLINK_TREE+=	gnuradio-fec

.if !defined(GNURADIO_FEC_BUILDLINK3_MK)
GNURADIO_FEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.8.1.0
BUILDLINK_ABI_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.8.1.0
BUILDLINK_PKGSRCDIR.gnuradio-fec?=	../../ham/gnuradio-fec
.endif # GNURADIO_FEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-fec
