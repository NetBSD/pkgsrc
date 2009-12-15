# $NetBSD: buildlink3.mk,v 1.14 2009/12/15 21:40:00 joerg Exp $

BUILDLINK_TREE+=	g-wrap

.if !defined(G_WRAP_BUILDLINK3_MK)
G_WRAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.g-wrap+=	g-wrap>=1.9.5
BUILDLINK_ABI_DEPENDS.g-wrap?=	g-wrap>=1.9.12nb2
BUILDLINK_PKGSRCDIR.g-wrap?=	../../devel/g-wrap

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.endif # G_WRAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-g-wrap
