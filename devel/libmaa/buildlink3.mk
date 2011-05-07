# $NetBSD: buildlink3.mk,v 1.4 2011/05/07 10:06:02 cheusov Exp $

BUILDLINK_TREE+=	libmaa

.if !defined(LIBMAA_BUILDLINK3_MK)
LIBMAA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmaa+=	libmaa>=1.3.0
BUILDLINK_PKGSRCDIR.libmaa?=	../../devel/libmaa
.endif # LIBMAA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmaa
