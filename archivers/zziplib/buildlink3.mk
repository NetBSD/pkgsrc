# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:23:51 joerg Exp $

BUILDLINK_TREE+=	zziplib

.if !defined(ZZIPLIB_BUILDLINK3_MK)
ZZIPLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zziplib+=	zziplib>=0.10.82
BUILDLINK_PKGSRCDIR.zziplib?=	../../archivers/zziplib

.include "../../devel/zlib/buildlink3.mk"
.endif # ZZIPLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-zziplib
