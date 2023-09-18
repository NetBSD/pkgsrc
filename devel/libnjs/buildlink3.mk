# $NetBSD: buildlink3.mk,v 1.3 2023/09/18 17:49:31 osa Exp $

BUILDLINK_TREE+=	libnjs

.if !defined(LIBNJS_BUILDLINK3_MK)
LIBNJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnjs+=	libnjs>=0.8.1
BUILDLINK_PKGSRCDIR.libnjs?=	../../devel/libnjs

.endif # LIBNJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnjs
