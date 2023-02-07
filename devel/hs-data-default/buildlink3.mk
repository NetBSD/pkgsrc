# $NetBSD: buildlink3.mk,v 1.10 2023/02/07 01:40:31 pho Exp $

BUILDLINK_TREE+=	hs-data-default

.if !defined(HS_DATA_DEFAULT_BUILDLINK3_MK)
HS_DATA_DEFAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-default+=	hs-data-default>=0.7.1
BUILDLINK_ABI_DEPENDS.hs-data-default+=	hs-data-default>=0.7.1.1nb5
BUILDLINK_PKGSRCDIR.hs-data-default?=	../../devel/hs-data-default

.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-data-default-instances-containers/buildlink3.mk"
.include "../../devel/hs-data-default-instances-dlist/buildlink3.mk"
.include "../../devel/hs-data-default-instances-old-locale/buildlink3.mk"
.endif	# HS_DATA_DEFAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-default
