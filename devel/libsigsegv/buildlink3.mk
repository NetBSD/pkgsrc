# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:22 joerg Exp $

BUILDLINK_TREE+=	libsigsegv

.if !defined(LIBSIGSEGV_BUILDLINK3_MK)
LIBSIGSEGV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsigsegv+=	libsigsegv>=2.2
BUILDLINK_PKGSRCDIR.libsigsegv?=	../../devel/libsigsegv
.endif # LIBSIGSEGV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsigsegv
