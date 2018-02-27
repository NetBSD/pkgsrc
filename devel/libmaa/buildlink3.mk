# $NetBSD: buildlink3.mk,v 1.5 2018/02/27 19:36:06 cheusov Exp $

BUILDLINK_TREE+=	libmaa

.if !defined(LIBMAA_BUILDLINK3_MK)
LIBMAA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmaa+=	libmaa>=1.4.0
BUILDLINK_PKGSRCDIR.libmaa?=	../../devel/libmaa
.endif # LIBMAA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmaa
