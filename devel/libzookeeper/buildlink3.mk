# $NetBSD: buildlink3.mk,v 1.1 2015/10/09 13:59:57 fhajny Exp $

BUILDLINK_TREE+=	libzookeeper

.if !defined(LIBZOOKEEPER_BUILDLINK3_MK)
LIBZOOKEEPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzookeeper+=	libzookeeper>=3.4.0
BUILDLINK_PKGSRCDIR.libzookeeper?=	../../devel/libzookeeper

.endif # LIBZOOKEEPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzookeeper
