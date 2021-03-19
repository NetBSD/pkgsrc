# $NetBSD: buildlink3.mk,v 1.1 2021/03/19 21:48:27 markd Exp $

BUILDLINK_TREE+=	libcutl

.if !defined(LIBCUTL_BUILDLINK3_MK)
LIBCUTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcutl+=	libcutl>=1.10.0
BUILDLINK_PKGSRCDIR.libcutl?=	../../devel/libcutl
.endif	# LIBCUTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcutl
