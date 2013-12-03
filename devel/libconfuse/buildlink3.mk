# $NetBSD: buildlink3.mk,v 1.1 2013/12/03 01:27:43 mef Exp $

BUILDLINK_TREE+=	libconfuse

.if !defined(LIBCONFUSE_BUILDLINK3_MK)
LIBCONFUSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libconfuse+=	libconfuse>=2.7
BUILDLINK_PKGSRCDIR.libconfuse?=	../../devel/libconfuse

.endif # LIBCONFUSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libconfuse
