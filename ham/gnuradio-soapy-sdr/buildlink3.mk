# $NetBSD: buildlink3.mk,v 1.3 2022/03/12 23:04:46 tnn Exp $

BUILDLINK_TREE+=	gnuradio-soapy-sdr

.if !defined(GNURADIO_SOAPY_SDR_BUILDLINK3_MK)
GNURADIO_SOAPY_SDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-soapy-sdr+=	gnuradio-soapy-sdr>=3.10.1.1
BUILDLINK_PKGSRCDIR.gnuradio-soapy-sdr?=	../../ham/gnuradio-soapy-sdr

.include	"../../ham/soapy-sdr/buildlink3.mk"
.endif	# GNURADIO_SOAPY_SDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-soapy-sdr
