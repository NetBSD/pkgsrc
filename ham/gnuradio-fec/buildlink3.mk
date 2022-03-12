# $NetBSD: buildlink3.mk,v 1.5 2022/03/12 23:04:45 tnn Exp $

BUILDLINK_TREE+=	gnuradio-fec

.if !defined(GNURADIO_FEC_BUILDLINK3_MK)
GNURADIO_FEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.10.1.1
BUILDLINK_PKGSRCDIR.gnuradio-fec?=	../../ham/gnuradio-fec
.endif # GNURADIO_FEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-fec
