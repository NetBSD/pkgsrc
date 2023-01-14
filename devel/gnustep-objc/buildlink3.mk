# $NetBSD: buildlink3.mk,v 1.15 2023/01/14 01:30:53 manu Exp $

BUILDLINK_TREE+=	gnustep-objc

.if !defined(GNUSTEP_OBJC_BUILDLINK3_MK)
GNUSTEP_OBJC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-objc+=	gnustep-objc>=1.3.0
BUILDLINK_ABI_DEPENDS.gnustep-objc+=	gnustep-objc>=1.3.0nb1
BUILDLINK_PKGSRCDIR.gnustep-objc?=	../../devel/gnustep-objc

BUILDLINK_CFLAGS.gnustep-objc+=		-I${BUILDLINK_PREFIX.gnustep-objc}/include/objc
BUILDLINK_LDFLAGS.gnustep-objc+=	-lobjc -lpthread

.endif # GNUSTEP_OBJC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-objc
