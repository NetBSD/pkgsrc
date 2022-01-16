# $NetBSD: buildlink3.mk,v 1.2 2022/01/16 18:06:26 tnn Exp $

BUILDLINK_TREE+=	gnuradio-soapy-sdr

.if !defined(GNURADIO_SOAPY_SDR_BUILDLINK3_MK)
GNURADIO_SOAPY_SDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-soapy-sdr+=	gnuradio-soapy-sdr>=3.10.0.0
BUILDLINK_PKGSRCDIR.gnuradio-soapy-sdr?=	../../ham/gnuradio-soapy-sdr

.include	"../../ham/soapy-sdr/buildlink3.mk"
.endif	# GNURADIO_SOAPY_SDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-soapy-sdr
