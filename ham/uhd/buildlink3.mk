# $NetBSD: buildlink3.mk,v 1.13 2026/08/24 08:42:24 adam Exp $

BUILDLINK_TREE+=	uhd

.if !defined(UHD_BUILDLINK3_MK)
UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhd+=	uhd>=2.22
BUILDLINK_ABI_DEPENDS.uhd+=	uhd>=4.10.0.0nb3
BUILDLINK_PKGSRCDIR.uhd?=	../../ham/uhd

# gnuradio-uhd FindUHD.cmake uses this env var as a hint for finding uhd
CONFIGURE_ENV+=		UHD_DIR=${BUILDLINK_DIR}

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.endif # UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-uhd
