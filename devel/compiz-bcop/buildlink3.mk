# $NetBSD: buildlink3.mk,v 1.5 2013/06/30 20:16:15 rodent Exp $

BUILDLINK_TREE+=	compiz-bcop

.if !defined(COMPIZ_BCOP_BUILDLINK3_MK)
COMPIZ_BCOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiz-bcop+=	compiz-bcop>=0.6.0
BUILDLINK_PKGSRCDIR.compiz-bcop?=	../../devel/compiz-bcop

BUILDLINK_DEPMETHOD.compiz-bcop?=	build

.endif # COMPIZ_BCOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiz-bcop
