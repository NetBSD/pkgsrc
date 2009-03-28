# $NetBSD: buildlink3.mk,v 1.1 2009/03/28 15:47:12 wiz Exp $

BUILDLINK_TREE+=	unshield

.if !defined(UNSHIELD_BUILDLINK3_MK)
UNSHIELD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unshield+=	unshield>=0.5.1
BUILDLINK_PKGSRCDIR.unshield?=	../../archivers/unshield

.include "../../devel/zlib/buildlink3.mk"
.endif	# UNSHIELD_BUILDLINK3_MK

BUILDLINK_TREE+=	-unshield
