# $NetBSD: buildlink3.mk,v 1.1 2016/09/18 14:13:20 kamil Exp $

BUILDLINK_TREE+=	tinycthread

.if !defined(TINYCTHREAD_BUILDLINK3_MK)
TINYCTHREAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tinycthread+=	tinycthread>=1.1
BUILDLINK_PKGSRCDIR.tinycthread?=	../../devel/tinycthread
.endif	# TINYCTHREAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-tinycthread
