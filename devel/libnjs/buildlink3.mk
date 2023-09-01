# $NetBSD: buildlink3.mk,v 1.2 2023/09/01 17:06:02 osa Exp $

BUILDLINK_TREE+=	libnjs

.if !defined(LIBNJS_BUILDLINK3_MK)
LIBNJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnjs+=	libnjs>=0.8.0
BUILDLINK_PKGSRCDIR.libnjs?=	../../devel/libnjs

.endif # LIBNJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnjs
