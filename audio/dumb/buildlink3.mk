# $NetBSD: buildlink3.mk,v 1.1 2020/03/17 21:41:50 nia Exp $

BUILDLINK_TREE+=	dumb

.if !defined(DUMB_BUILDLINK3_MK)
DUMB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dumb+=	dumb>=2.0.3
BUILDLINK_PKGSRCDIR.dumb?=	../../audio/dumb
.endif	# DUMB_BUILDLINK3_MK

BUILDLINK_TREE+=	-dumb
