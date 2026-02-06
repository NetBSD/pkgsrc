# $NetBSD: buildlink3.mk,v 1.5 2026/02/06 10:05:44 wiz Exp $

BUILDLINK_TREE+=	libppd

.if !defined(LIBPPD_BUILDLINK3_MK)
LIBPPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libppd+=	libppd>=2.1.1
BUILDLINK_ABI_DEPENDS.libppd?=	libppd>=2.1.1nb5
BUILDLINK_PKGSRCDIR.libppd?=	../../print/libppd

.include "../../print/libcupsfilters/buildlink3.mk"
.endif	# LIBPPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libppd
