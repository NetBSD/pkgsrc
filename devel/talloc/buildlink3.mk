# $NetBSD: buildlink3.mk,v 1.1 2014/01/09 11:57:04 wiz Exp $

BUILDLINK_TREE+=	talloc

.if !defined(TALLOC_BUILDLINK3_MK)
TALLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.talloc+=	talloc>=2.1.0
BUILDLINK_PKGSRCDIR.talloc?=	../../devel/talloc
.endif	# TALLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-talloc
