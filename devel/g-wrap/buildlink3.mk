# $NetBSD: buildlink3.mk,v 1.21 2022/03/07 22:59:49 wiz Exp $

BUILDLINK_TREE+=	g-wrap

.if !defined(G_WRAP_BUILDLINK3_MK)
G_WRAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.g-wrap+=	g-wrap>=1.9.5
BUILDLINK_ABI_DEPENDS.g-wrap+=	g-wrap>=1.9.15nb3
BUILDLINK_PKGSRCDIR.g-wrap?=	../../devel/g-wrap

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
.endif # G_WRAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-g-wrap
