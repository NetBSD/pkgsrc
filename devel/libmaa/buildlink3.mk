# $NetBSD: buildlink3.mk,v 1.3 2009/11/19 01:19:23 reed Exp $

BUILDLINK_TREE+=	libmaa

.if !defined(LIBMAA_BUILDLINK3_MK)
LIBMAA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmaa+=	libmaa>=1.2.0
BUILDLINK_PKGSRCDIR.libmaa?=	../../devel/libmaa
.endif # LIBMAA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmaa
