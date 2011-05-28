# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/05/28 09:48:07 cheusov Exp $

BUILDLINK_TREE+=	libuxre

.if !defined(LIBUXRE_BUILDLINK3_MK)
LIBUXRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libuxre+=	libuxre>=060122
BUILDLINK_PKGSRCDIR.libuxre?=	../../devel/libuxre
BUILDLINK_INCDIRS.libuxre+=	include/uxre
.endif # LIBUXRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libuxre
