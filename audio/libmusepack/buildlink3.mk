# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:23:56 joerg Exp $

BUILDLINK_TREE+=	libmusepack

.if !defined(LIBMUSEPACK_BUILDLINK3_MK)
LIBMUSEPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmusepack+=		libmusepack>=1.0.3
BUILDLINK_PKGSRCDIR.libmusepack?=	../../audio/libmusepack
.endif # LIBMUSEPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmusepack
