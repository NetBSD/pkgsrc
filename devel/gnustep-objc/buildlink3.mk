# $NetBSD: buildlink3.mk,v 1.16 2025/02/20 14:24:02 manu Exp $

BUILDLINK_TREE+=	gnustep-objc

.if !defined(GNUSTEP_OBJC_BUILDLINK3_MK)
GNUSTEP_OBJC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-objc+=	gnustep-objc>=2.2.1
BUILDLINK_ABI_DEPENDS.gnustep-objc+=	gnustep-objc>=2.2.1
BUILDLINK_PKGSRCDIR.gnustep-objc?=	../../devel/gnustep-objc

BUILDLINK_CFLAGS.gnustep-objc+=		-I${BUILDLINK_PREFIX.gnustep-objc}/include/objc
BUILDLINK_LDFLAGS.gnustep-objc+=	-lobjc -lpthread

.endif # GNUSTEP_OBJC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-objc
