# $NetBSD: buildlink3.mk,v 1.9 2023/08/14 05:23:46 wiz Exp $

BUILDLINK_TREE+=	zziplib

.if !defined(ZZIPLIB_BUILDLINK3_MK)
ZZIPLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zziplib+=	zziplib>=0.10.82
BUILDLINK_ABI_DEPENDS.zziplib+=	zziplib>=0.13.72nb2
BUILDLINK_PKGSRCDIR.zziplib?=	../../archivers/zziplib

.include "../../devel/zlib/buildlink3.mk"
.endif # ZZIPLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-zziplib
