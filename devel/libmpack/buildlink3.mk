# $NetBSD: buildlink3.mk,v 1.1 2022/04/20 17:56:29 nia Exp $

BUILDLINK_TREE+=	libmpack

.if !defined(LIBMPACK_BUILDLINK3_MK)
LIBMPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmpack+=	libmpack>=1.0.0
BUILDLINK_PKGSRCDIR.libmpack?=		../../devel/libmpack
.endif	# LIBMPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmpack
