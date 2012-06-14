# $NetBSD: buildlink3.mk,v 1.8 2012/06/14 07:43:12 sbd Exp $

BUILDLINK_TREE+=	lasso

.if !defined(LASSO_BUILDLINK3_MK)
LASSO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lasso+=	lasso>=2.2.1
BUILDLINK_ABI_DEPENDS.lasso+=	lasso>=2.3.5nb5
BUILDLINK_PKGSRCDIR.lasso?=	../../security/lasso

.include "../../security/xmlsec1/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.endif # LASSO_BUILDLINK3_MK

BUILDLINK_TREE+=	-lasso
