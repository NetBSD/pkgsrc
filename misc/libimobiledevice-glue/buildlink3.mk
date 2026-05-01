# $NetBSD: buildlink3.mk,v 1.1 2026/05/01 19:49:47 vins Exp $

BUILDLINK_TREE+=	libimobiledevice-glue

.if !defined(LIBIMOBILEDEVICE_GLUE_BUILDLINK3_MK)
LIBIMOBILEDEVICE_GLUE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libimobiledevice-glue+=	libimobiledevice-glue>=1.3.2
BUILDLINK_PKGSRCDIR.libimobiledevice-glue?=	../../misc/libimobiledevice-glue

.include "../../textproc/libplist/buildlink3.mk"
.endif	# LIBIMOBILEDEVICE_GLUE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libimobiledevice-glue
