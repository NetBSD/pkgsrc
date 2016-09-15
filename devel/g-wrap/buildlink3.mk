# $NetBSD: buildlink3.mk,v 1.19 2016/09/15 14:32:39 wiz Exp $

BUILDLINK_TREE+=	g-wrap

.if !defined(G_WRAP_BUILDLINK3_MK)
G_WRAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.g-wrap+=	g-wrap>=1.9.5
BUILDLINK_ABI_DEPENDS.g-wrap+=	g-wrap>=1.9.15
BUILDLINK_PKGSRCDIR.g-wrap?=	../../devel/g-wrap

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
.endif # G_WRAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-g-wrap
