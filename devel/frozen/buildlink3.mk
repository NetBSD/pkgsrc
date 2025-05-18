# $NetBSD: buildlink3.mk,v 1.2 2025/05/18 01:04:32 ryoon Exp $

BUILDLINK_TREE+=	frozen

.if !defined(FROZEN_BUILDLINK3_MK)
FROZEN_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.frozen?=	build

BUILDLINK_API_DEPENDS.frozen+=	frozen>=1.2.0
BUILDLINK_PKGSRCDIR.frozen?=	../../devel/frozen
.endif	# FROZEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-frozen
