# $NetBSD: buildlink3.mk,v 1.12 2022/06/28 11:31:46 wiz Exp $

BUILDLINK_TREE+=	libffi

.if !defined(LIBFFI_BUILDLINK3_MK)
LIBFFI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libffi+=	libffi>=1.20
BUILDLINK_ABI_DEPENDS.libffi+=	libffi>=3.4.2nb3
BUILDLINK_PKGSRCDIR.libffi?=	../../devel/libffi
.endif # LIBFFI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libffi
