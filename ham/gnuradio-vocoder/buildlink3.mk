# $NetBSD: buildlink3.mk,v 1.3 2020/08/30 21:12:55 tnn Exp $

BUILDLINK_TREE+=	gnuradio-vocoder

.if !defined(GNURADIO_VOCODER_BUILDLINK3_MK)
GNURADIO_VOCODER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-vocoder+=	gnuradio-vocoder>=3.8.1.0
BUILDLINK_ABI_DEPENDS.gnuradio-vocoder+=	gnuradio-vocoder>=3.8.1.0
BUILDLINK_PKGSRCDIR.gnuradio-vocoder?=		../../ham/gnuradio-vocoder
.endif # GNURADIO_VOCODER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-vocoder
