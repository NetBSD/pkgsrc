# $NetBSD: buildlink3.mk,v 1.3 2021/12/11 14:57:51 tnn Exp $

BUILDLINK_TREE+=	gnuradio-uhd

.if !defined(GNURADIO_UHD_BUILDLINK3_MK)
GNURADIO_UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-uhd+=	gnuradio-uhd>=3.9.4.0
BUILDLINK_ABI_DEPENDS.gnuradio-uhd+=	gnuradio-uhd>=3.9.4.0
BUILDLINK_PKGSRCDIR.gnuradio-uhd?=	../../ham/gnuradio-uhd
.endif # GNURADIO_UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-uhd
