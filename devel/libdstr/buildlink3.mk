# $NetBSD: buildlink3.mk,v 1.1 2020/02/28 22:04:30 plunky Exp $

BUILDLINK_TREE+=	libdstr

.if !defined(LIBDSTR_BUILDLINK3_MK)
LIBDSTR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdstr+=	libdstr>=1.0
BUILDLINK_ABI_DEPENDS.libdstr+=	libdstr>=1.0
BUILDLINK_PKGSRCDIR.libdstr?=	../../devel/libdstr
.endif # LIBDSTR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdstr
