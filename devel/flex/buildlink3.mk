# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:13 joerg Exp $
#

BUILDLINK_TREE+=	flex

.if !defined(FLEX_BUILDLINK3_MK)
FLEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flex+=	flex>=2.5.4a
BUILDLINK_PKGSRCDIR.flex?=	../../devel/flex
BUILDLINK_DEPMETHOD.flex?=	build
.endif # FLEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-flex
