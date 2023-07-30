# $NetBSD: buildlink3.mk,v 1.3 2023/07/30 08:24:21 nia Exp $

BUILDLINK_TREE+=	dragonbox

.if !defined(DRAGONBOX_BUILDLINK3_MK)
DRAGONBOX_BUILDLINK3_MK:=

USE_CXX_FEATURES+=			c++17 # is_unsigned_v

BUILDLINK_API_DEPENDS.dragonbox+=	dragonbox>=1.1.3
BUILDLINK_PKGSRCDIR.dragonbox?=		../../math/dragonbox
.endif	# DRAGONBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-dragonbox
