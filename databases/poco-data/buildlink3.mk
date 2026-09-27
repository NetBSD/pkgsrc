# $NetBSD: buildlink3.mk,v 1.15 2026/09/27 11:35:22 tnn Exp $

BUILDLINK_TREE+=	poco-data

.if !defined(POCO_DATA_BUILDLINK3_MK)
POCO_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data+=	poco-data>=1.6.1
BUILDLINK_ABI_DEPENDS.poco-data+=	poco-data>=1.15.3nb2
BUILDLINK_PKGSRCDIR.poco-data?=		../../databases/poco-data

.include "../../devel/poco/buildlink3.mk"
.endif # POCO_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data
