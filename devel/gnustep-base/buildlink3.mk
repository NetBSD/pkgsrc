# $NetBSD: buildlink3.mk,v 1.46 2025/02/20 14:28:46 manu Exp $

BUILDLINK_TREE+=	gnustep-base

.if !defined(GNUSTEP_BASE_BUILDLINK3_MK)
GNUSTEP_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-base+=	gnustep-base>=1.31.0
BUILDLINK_ABI_DEPENDS.gnustep-base+=	gnustep-base>=1.31.0
BUILDLINK_PKGSRCDIR.gnustep-base?=	../../devel/gnustep-base

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-objc/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif # GNUSTEP_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-base
