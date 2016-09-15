# $NetBSD: buildlink3.mk,v 1.18 2016/09/15 00:01:43 gdt Exp $

BUILDLINK_TREE+=	g-wrap

.if !defined(G_WRAP_BUILDLINK3_MK)
G_WRAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.g-wrap+=	g-wrap>=1.9.5
BUILDLINK_ABI_DEPENDS.g-wrap+=	g-wrap>=1.9.14nb3
BUILDLINK_PKGSRCDIR.g-wrap?=	../../devel/g-wrap

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
.endif # G_WRAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-g-wrap
