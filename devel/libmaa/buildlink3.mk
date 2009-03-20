# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:20 joerg Exp $

BUILDLINK_TREE+=	libmaa

.if !defined(LIBMAA_BUILDLINK3_MK)
LIBMAA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmaa+=	libmaa>=0.990
BUILDLINK_PKGSRCDIR.libmaa?=	../../devel/libmaa
.endif # LIBMAA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmaa
