# $NetBSD: buildlink3.mk,v 1.2 2014/10/13 21:43:20 ryoon Exp $

BUILDLINK_TREE+=	orcus

.if !defined(ORCUS_BUILDLINK3_MK)
ORCUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orcus+=	orcus>=0.7.0
BUILDLINK_PKGSRCDIR.orcus?=	../../converters/orcus

#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.endif	# ORCUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-orcus
