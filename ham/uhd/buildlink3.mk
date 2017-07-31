# $NetBSD: buildlink3.mk,v 1.3 2017/07/31 21:09:27 wiz Exp $

BUILDLINK_TREE+=	uhd

.if !defined(UHD_BUILDLINK3_MK)
UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhd+=	uhd>=2.22
BUILDLINK_PKGSRCDIR.uhd?=	../../ham/uhd

# gnuradio-uhd FindUHD.cmake uses this env var as a hint for finding uhd
CONFIGURE_ENV+=		UHD_DIR=${BUILDLINK_DIR:Q}

.endif # UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-uhd
