# $NetBSD: buildlink3.mk,v 1.4 2022/01/16 18:06:26 tnn Exp $

BUILDLINK_TREE+=	gnuradio-fec

.if !defined(GNURADIO_FEC_BUILDLINK3_MK)
GNURADIO_FEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.10.0.0
BUILDLINK_PKGSRCDIR.gnuradio-fec?=	../../ham/gnuradio-fec
.endif # GNURADIO_FEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-fec
