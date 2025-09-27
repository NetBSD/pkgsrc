# $NetBSD: buildlink3.mk,v 1.10 2025/09/27 09:57:24 wiz Exp $

BUILDLINK_TREE+=	uhd

.if !defined(UHD_BUILDLINK3_MK)
UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhd+=	uhd>=2.22
BUILDLINK_ABI_DEPENDS.uhd+=	uhd>=4.8.0.0nb1
BUILDLINK_PKGSRCDIR.uhd?=	../../ham/uhd

# gnuradio-uhd FindUHD.cmake uses this env var as a hint for finding uhd
CONFIGURE_ENV+=		UHD_DIR=${BUILDLINK_DIR}

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.endif # UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-uhd
