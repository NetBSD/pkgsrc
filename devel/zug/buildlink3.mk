# $NetBSD: buildlink3.mk,v 1.1 2024/03/14 19:27:07 markd Exp $

BUILDLINK_TREE+=	zug

.if !defined(ZUG_BUILDLINK3_MK)
ZUG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zug+=	zug>=0.1.1
BUILDLINK_DEPMETHOD.zug?=	build
BUILDLINK_PKGSRCDIR.zug?=	../../devel/zug
.endif	# ZUG_BUILDLINK3_MK

BUILDLINK_TREE+=	-zug
