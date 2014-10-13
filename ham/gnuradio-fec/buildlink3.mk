# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 12:51:09 mef Exp $

BUILDLINK_TREE+=	gnuradio-fec

.if !defined(GNURADIO_FEC_BUILDLINK3_MK)
GNURADIO_FEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-fec?=	../../ham/gnuradio-fec
.endif # GNURADIO_FEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-fec
