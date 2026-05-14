# $NetBSD: buildlink3.mk,v 1.6 2026/05/14 16:41:56 ryoon Exp $

BUILDLINK_TREE+=	libppd

.if !defined(LIBPPD_BUILDLINK3_MK)
LIBPPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libppd+=	libppd>=2.1.1
BUILDLINK_ABI_DEPENDS.libppd?=	libppd>=2.1.1nb6
BUILDLINK_PKGSRCDIR.libppd?=	../../print/libppd

.include "../../print/libcupsfilters/buildlink3.mk"
.endif	# LIBPPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libppd
