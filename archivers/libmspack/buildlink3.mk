# $NetBSD: buildlink3.mk,v 1.1 2016/10/09 03:11:25 ryoon Exp $

BUILDLINK_TREE+=	libmspack

.if !defined(LIBMSPACK_BUILDLINK3_MK)
LIBMSPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmspack+=	libmspack>=0.5alpha
BUILDLINK_PKGSRCDIR.libmspack?=		../../archivers/libmspack

.endif	# LIBMSPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmspack
