# $NetBSD: buildlink3.mk,v 1.3 2016/09/20 10:52:53 wiz Exp $

BUILDLINK_TREE+=	orcus012

.if !defined(ORCUS012_BUILDLINK3_MK)
ORCUS012_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orcus012+=	orcus0.12>=0.12.0
BUILDLINK_PKGSRCDIR.orcus012?=	../../converters/orcus0.12

.include "../../devel/mdds1.2/buildlink3.mk"
.include "../../math/libixion/buildlink3.mk"
.endif	# ORCUS012_BUILDLINK3_MK

BUILDLINK_TREE+=	-orcus012
