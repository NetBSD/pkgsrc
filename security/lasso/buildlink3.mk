# $NetBSD: buildlink3.mk,v 1.13 2015/04/01 14:05:02 manu Exp $

BUILDLINK_TREE+=	lasso

.if !defined(LASSO_BUILDLINK3_MK)
LASSO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lasso+=	lasso>=2.2.1
BUILDLINK_ABI_DEPENDS.lasso+=	lasso>=2.3.6nb11
BUILDLINK_PKGSRCDIR.lasso?=	../../security/lasso

.include "../../security/xmlsec1/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.endif # LASSO_BUILDLINK3_MK

BUILDLINK_TREE+=	-lasso
