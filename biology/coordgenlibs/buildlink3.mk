# $NetBSD: buildlink3.mk,v 1.6 2023/01/22 16:28:12 ryoon Exp $

BUILDLINK_TREE+=	coordgenlibs

.if !defined(COORDGENLIBS_BUILDLINK3_MK)
COORDGENLIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.coordgenlibs+=	coordgenlibs>=1.4.2
BUILDLINK_ABI_DEPENDS.coordgenlibs?=	coordgenlibs>=1.4.2nb5
BUILDLINK_PKGSRCDIR.coordgenlibs?=	../../biology/coordgenlibs

.include "../../biology/maeparser/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.endif	# COORDGENLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-coordgenlibs
