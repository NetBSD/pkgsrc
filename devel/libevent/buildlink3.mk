# $NetBSD: buildlink3.mk,v 1.19 2011/02/11 21:13:47 tnn Exp $

BUILDLINK_TREE+=	libevent

.if !defined(LIBEVENT_BUILDLINK3_MK)
LIBEVENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libevent+=libevent>=0.6
BUILDLINK_ABI_DEPENDS.libevent+=libevent>=2.0.10
BUILDLINK_PKGSRCDIR.libevent?=	../../devel/libevent
.endif # LIBEVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libevent
