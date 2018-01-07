# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:03:53 rillig Exp $

BUILDLINK_TREE+=	unshield

.if !defined(UNSHIELD_BUILDLINK3_MK)
UNSHIELD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unshield+=	unshield>=0.5.1
BUILDLINK_PKGSRCDIR.unshield?=		../../archivers/unshield

.include "../../devel/zlib/buildlink3.mk"
.endif	# UNSHIELD_BUILDLINK3_MK

BUILDLINK_TREE+=	-unshield
