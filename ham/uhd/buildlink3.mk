# $NetBSD: buildlink3.mk,v 1.7 2023/08/14 05:24:39 wiz Exp $

BUILDLINK_TREE+=	uhd

.if !defined(UHD_BUILDLINK3_MK)
UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhd+=	uhd>=2.22
BUILDLINK_ABI_DEPENDS.uhd+=	uhd>=4.4.0.0nb2
BUILDLINK_PKGSRCDIR.uhd?=	../../ham/uhd

# gnuradio-uhd FindUHD.cmake uses this env var as a hint for finding uhd
CONFIGURE_ENV+=		UHD_DIR=${BUILDLINK_DIR}

.endif # UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-uhd
