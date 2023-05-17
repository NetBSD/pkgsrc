# $NetBSD: buildlink3.mk,v 1.1 2023/05/17 16:44:51 osa Exp $

BUILDLINK_TREE+=	libnjs

.if !defined(LIBNJS_BUILDLINK3_MK)
LIBNJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnjs+=	libnjs>=0.7.12
BUILDLINK_PKGSRCDIR.libnjs?=	../../devel/libnjs

.endif # LIBNJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnjs
