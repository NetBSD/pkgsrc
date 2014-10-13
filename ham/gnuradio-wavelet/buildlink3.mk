# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 12:51:10 mef Exp $

BUILDLINK_TREE+=	gnuradio-wavelet

.if !defined(GNURADIO_WAVELET_BUILDLINK3_MK)
GNURADIO_WAVELET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-wavelet+=	gnuradio-wavelet>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-wavelet+=	gnuradio-wavelet>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-wavelet?=	../../ham/gnuradio-wavelet
.endif # GNURADIO_WAVELET_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-wavelet
