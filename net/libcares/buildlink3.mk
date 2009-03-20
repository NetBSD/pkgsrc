# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:09 joerg Exp $

BUILDLINK_TREE+=	libcares

.if !defined(LIBCARES_BUILDLINK3_MK)
LIBCARES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcares+=	libcares>=1.3.0nb1
BUILDLINK_PKGSRCDIR.libcares?=	../../net/libcares
.endif # LIBCARES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcares
