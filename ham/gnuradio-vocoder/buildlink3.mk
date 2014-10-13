# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 12:51:10 mef Exp $

BUILDLINK_TREE+=	gnuradio-vocoder

.if !defined(GNURADIO_VOCODER_BUILDLINK3_MK)
GNURADIO_VOCODER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-vocoder+=	gnuradio-vocoder>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-vocoder+=	gnuradio-vocoder>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-vocoder?=	../../ham/gnuradio-vocoder
.endif # GNURADIO_VOCODER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-vocoder
