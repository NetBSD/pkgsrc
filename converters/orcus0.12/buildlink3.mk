# $NetBSD: buildlink3.mk,v 1.2 2016/09/19 14:20:33 wiz Exp $

BUILDLINK_TREE+=	orcus012

.if !defined(ORCUS012_BUILDLINK3_MK)
ORCUS012_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orcus012+=	orcus0.12>=0.12.0
BUILDLINK_PKGSRCDIR.orcus012?=	../../converters/orcus0.12

#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.endif	# ORCUS012_BUILDLINK3_MK

BUILDLINK_TREE+=	-orcus012
