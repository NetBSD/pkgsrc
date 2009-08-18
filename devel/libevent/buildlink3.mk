# $NetBSD: buildlink3.mk,v 1.18 2009/08/18 16:53:14 drochner Exp $

BUILDLINK_TREE+=	libevent

.if !defined(LIBEVENT_BUILDLINK3_MK)
LIBEVENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libevent+=libevent>=0.6
BUILDLINK_ABI_DEPENDS.libevent+=libevent>=1.4.3
BUILDLINK_PKGSRCDIR.libevent?=	../../devel/libevent
.endif # LIBEVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libevent
