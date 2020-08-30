# $NetBSD: buildlink3.mk,v 1.3 2020/08/30 21:14:07 tnn Exp $

BUILDLINK_TREE+=	gnuradio-wavelet

.if !defined(GNURADIO_WAVELET_BUILDLINK3_MK)
GNURADIO_WAVELET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-wavelet+=	gnuradio-wavelet>=3.8.1.0
BUILDLINK_ABI_DEPENDS.gnuradio-wavelet+=	gnuradio-wavelet>=3.8.1.0
BUILDLINK_PKGSRCDIR.gnuradio-wavelet?=		../../ham/gnuradio-wavelet
.endif # GNURADIO_WAVELET_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-wavelet
