# $NetBSD: buildlink3.mk,v 1.3 2011/02/06 06:12:21 schnoebe Exp $

BUILDLINK_TREE+=	poco-data

.if !defined(POCO_DATA_BUILDLINK3_MK)
POCO_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data+=	poco-data>=1.3.5
BUILDLINK_ABI_DEPENDS.poco-data?=	poco-data>=1.3.5nb1
BUILDLINK_PKGSRCDIR.poco-data?=	../../databases/poco-data

.include "../../devel/poco/buildlink3.mk"
.endif # POCO_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data
