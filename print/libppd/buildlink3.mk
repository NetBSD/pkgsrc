# $NetBSD: buildlink3.mk,v 1.1 2025/08/16 01:02:27 ryoon Exp $

BUILDLINK_TREE+=	libppd

.if !defined(LIBPPD_BUILDLINK3_MK)
LIBPPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libppd+=	libppd>=2.1.1
BUILDLINK_PKGSRCDIR.libppd?=	../../print/libppd

.include "../../print/libcupsfilters/buildlink3.mk"
.endif	# LIBPPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libppd
