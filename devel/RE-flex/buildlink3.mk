# $NetBSD: buildlink3.mk,v 1.1 2020/06/15 15:11:50 scole Exp $
#

BUILDLINK_TREE+=	RE-flex

.if !defined(RE_FLEX_BUILDLINK3_MK)
RE_FLEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.RE-flex+=	RE-flex>=2.0.1
BUILDLINK_PKGSRCDIR.RE-flex?=	../../devel/RE-flex
.endif	# RE_FLEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-RE-flex
