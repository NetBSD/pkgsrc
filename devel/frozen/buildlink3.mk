# $NetBSD: buildlink3.mk,v 1.1 2023/10/15 19:26:40 ryoon Exp $

BUILDLINK_TREE+=	frozen

.if !defined(FROZEN_BUILDLINK3_MK)
FROZEN_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.frozen?=	build

BUILDLINK_API_DEPENDS.frozen+=	frozen>=1.1.1
BUILDLINK_PKGSRCDIR.frozen?=	../../devel/frozen
.endif	# FROZEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-frozen
