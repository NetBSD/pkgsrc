# $NetBSD: buildlink3.mk,v 1.1 2022/08/24 12:53:24 ryoon Exp $

BUILDLINK_TREE+=	dragonbox

.if !defined(DRAGONBOX_BUILDLINK3_MK)
DRAGONBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dragonbox+=	dragonbox>=1.1.3
BUILDLINK_PKGSRCDIR.dragonbox?=		../../math/dragonbox
.endif	# DRAGONBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-dragonbox
