# $NetBSD: buildlink3.mk,v 1.3 2017/10/06 14:16:00 hauke Exp $

BUILDLINK_TREE+=	libfprint

.if !defined(LIBFPRINT_BUILDLINK3_MK)
LIBFPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfprint+=	libfprint>=0.7.0
BUILDLINK_ABI_DEPENDS.libfprint+=	libfprint>=0.7.0
BUILDLINK_PKGSRCDIR.libfprint?=		../../security/libfprint
.endif # LIBFPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfprint
