# $NetBSD: buildlink3.mk,v 1.9 2012/09/15 00:22:43 asau Exp $

BUILDLINK_TREE+=	libffi

.if !defined(LIBFFI_BUILDLINK3_MK)
LIBFFI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libffi+=	libffi>=1.20
BUILDLINK_ABI_DEPENDS.libffi+=	libffi>=3.0.11
BUILDLINK_PKGSRCDIR.libffi?=	../../devel/libffi
.endif # LIBFFI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libffi
