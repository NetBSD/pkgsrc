# $NetBSD: buildlink3.mk,v 1.8 2010/07/25 13:09:42 obache Exp $

BUILDLINK_TREE+=	libcares

.if !defined(LIBCARES_BUILDLINK3_MK)
LIBCARES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcares+=	libcares>=1.3.0nb1
BUILDLINK_ABI_DEPENDS.libcares+=	libcares>=1.6.0
BUILDLINK_PKGSRCDIR.libcares?=	../../net/libcares
.endif # LIBCARES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcares
