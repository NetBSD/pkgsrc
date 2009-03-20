# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:17 joerg Exp $

BUILDLINK_TREE+=	libffi

.if !defined(LIBFFI_BUILDLINK3_MK)
LIBFFI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libffi+=	libffi>=1.20
BUILDLINK_ABI_DEPENDS.libffi+=	libffi>=2.0betanb1
#BUILDLINK_API_DEPENDS.libffi+=	libffi>=3.0.6
BUILDLINK_PKGSRCDIR.libffi?=	../../devel/libffi
.endif # LIBFFI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libffi
