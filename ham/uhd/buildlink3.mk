# $NetBSD: buildlink3.mk,v 1.6 2022/01/04 17:29:06 adam Exp $

BUILDLINK_TREE+=	uhd

.if !defined(UHD_BUILDLINK3_MK)
UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhd+=	uhd>=2.22
BUILDLINK_ABI_DEPENDS.uhd+=	uhd>=4.1.0.4
BUILDLINK_PKGSRCDIR.uhd?=	../../ham/uhd

# gnuradio-uhd FindUHD.cmake uses this env var as a hint for finding uhd
CONFIGURE_ENV+=		UHD_DIR=${BUILDLINK_DIR}

.endif # UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-uhd
