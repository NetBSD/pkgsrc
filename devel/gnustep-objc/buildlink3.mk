# $NetBSD: buildlink3.mk,v 1.12 2020/04/16 09:28:39 manu Exp $

BUILDLINK_TREE+=	gnustep-objc

.if !defined(GNUSTEP_OBJC_BUILDLINK3_MK)
GNUSTEP_OBJC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-objc+=	gnustep-objc>=1.3.0
BUILDLINK_ABI_DEPENDS.gnustep-objc+=	gnustep-objc>=1.3.0nb1
BUILDLINK_PKGSRCDIR.gnustep-objc?=	../../devel/gnustep-objc

BUILDLINK_CFLAGS.gnustep-objc+=	-I${BUILDLINK_PREFIX.gnustep-objc}/include/objc
BUILDLINK_LDFLAGS.gnustep-objc+=	-lobjc -lpthread
.if ${OPSYS} == "NetBSD"
# Missing _Unwind_* symbols in gnustep objc.so, needs to come from somewhere...
BUILDLINK_LDFLAGS.gnustep-objc+=	-lgcc_s
.endif

.include "../../devel/gnustep-make/buildlink3.mk"
.endif # GNUSTEP_OBJC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-objc
