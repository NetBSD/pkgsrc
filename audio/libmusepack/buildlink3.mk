# $NetBSD: buildlink3.mk,v 1.9 2018/01/07 13:03:55 rillig Exp $

BUILDLINK_TREE+=	libmusepack

.if !defined(LIBMUSEPACK_BUILDLINK3_MK)
LIBMUSEPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmusepack+=	libmusepack>=1.0.3
BUILDLINK_PKGSRCDIR.libmusepack?=	../../audio/libmusepack
.endif # LIBMUSEPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmusepack
