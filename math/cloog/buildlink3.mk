# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/04/08 20:47:52 wiz Exp $

BUILDLINK_TREE+=	cloog

.if !defined(CLOOG_BUILDLINK3_MK)
CLOOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cloog+=	cloog>=0.16.2
BUILDLINK_PKGSRCDIR.cloog?=	../../wip/cloog

.endif # CLOOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-cloog
