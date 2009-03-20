# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:18 joerg Exp $

BUILDLINK_TREE+=	libfprint

.if !defined(LIBFPRINT_BUILDLINK3_MK)
LIBFPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfprint+=	libfprint>=0.0.6
BUILDLINK_ABI_DEPENDS.libfprint+=	libfprint>=0.0.6
BUILDLINK_PKGSRCDIR.libfprint?=		../../security/libfprint
.endif # LIBFPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfprint
