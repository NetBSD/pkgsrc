# $NetBSD: buildlink3.mk,v 1.5 2022/03/12 23:04:46 tnn Exp $

BUILDLINK_TREE+=	gnuradio-uhd

.if !defined(GNURADIO_UHD_BUILDLINK3_MK)
GNURADIO_UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-uhd+=	gnuradio-uhd>=3.10.1.1
BUILDLINK_PKGSRCDIR.gnuradio-uhd?=	../../ham/gnuradio-uhd
.endif # GNURADIO_UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-uhd
