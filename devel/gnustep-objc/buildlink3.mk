# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:14 joerg Exp $

BUILDLINK_TREE+=	gnustep-objc

.if !defined(GNUSTEP_OBJC_BUILDLINK3_MK)
GNUSTEP_OBJC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-objc+=	gnustep-objc>=1.3.0
BUILDLINK_ABI_DEPENDS.gnustep-objc?=	gnustep-objc>=1.3.0nb1
BUILDLINK_PKGSRCDIR.gnustep-objc?=	../../devel/gnustep-objc

.include "../../devel/gnustep-make/buildlink3.mk"
.endif # GNUSTEP_OBJC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-objc
