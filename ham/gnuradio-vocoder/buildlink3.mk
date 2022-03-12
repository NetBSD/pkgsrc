# $NetBSD: buildlink3.mk,v 1.6 2022/03/12 23:04:46 tnn Exp $

BUILDLINK_TREE+=	gnuradio-vocoder

.if !defined(GNURADIO_VOCODER_BUILDLINK3_MK)
GNURADIO_VOCODER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-vocoder+=	gnuradio-vocoder>=3.10.1.1
BUILDLINK_PKGSRCDIR.gnuradio-vocoder?=		../../ham/gnuradio-vocoder
.endif # GNURADIO_VOCODER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-vocoder
