# $NetBSD: buildlink3.mk,v 1.34 2020/04/16 09:35:36 manu Exp $

BUILDLINK_TREE+=	gnustep-base

.if !defined(GNUSTEP_BASE_BUILDLINK3_MK)
GNUSTEP_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-base+=	gnustep-base>=1.24.0
BUILDLINK_ABI_DEPENDS.gnustep-base+=	gnustep-base>=1.24.0nb22
BUILDLINK_PKGSRCDIR.gnustep-base?=	../../devel/gnustep-base

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-objc/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif # GNUSTEP_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-base
