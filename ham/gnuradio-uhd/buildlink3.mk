# $NetBSD: buildlink3.mk,v 1.7 2025/02/27 13:49:54 adam Exp $

BUILDLINK_TREE+=	gnuradio-uhd

.if !defined(GNURADIO_UHD_BUILDLINK3_MK)
GNURADIO_UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-uhd+=	gnuradio-uhd>=3.10.1.1
BUILDLINK_ABI_DEPENDS.gnuradio-uhd?=	gnuradio-uhd>=3.10.7.0nb1
BUILDLINK_PKGSRCDIR.gnuradio-uhd?=	../../ham/gnuradio-uhd

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/uhd/buildlink3.mk"
.endif # GNURADIO_UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-uhd
