# $NetBSD: buildlink3.mk,v 1.28 2023/11/08 13:20:47 wiz Exp $

BUILDLINK_TREE+=	lasso

.if !defined(LASSO_BUILDLINK3_MK)
LASSO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lasso+=	lasso>=2.2.1
BUILDLINK_ABI_DEPENDS.lasso+=	lasso>=2.7.0nb11
BUILDLINK_PKGSRCDIR.lasso?=	../../security/lasso

.include "../../security/xmlsec1/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.endif # LASSO_BUILDLINK3_MK

BUILDLINK_TREE+=	-lasso
