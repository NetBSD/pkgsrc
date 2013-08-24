# $NetBSD: buildlink3.mk,v 1.1 2013/08/24 16:12:10 jaapb Exp $

BUILDLINK_TREE+=	orcus

.if !defined(ORCUS_BUILDLINK3_MK)
ORCUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orcus+=	orcus>=0.5.1
BUILDLINK_PKGSRCDIR.orcus?=	../../converters/orcus

#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.endif	# ORCUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-orcus
