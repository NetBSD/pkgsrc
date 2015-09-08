# $NetBSD: buildlink3.mk,v 1.3 2015/09/08 19:40:59 wiz Exp $

BUILDLINK_TREE+=	orcus

.if !defined(ORCUS_BUILDLINK3_MK)
ORCUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orcus+=	orcus>=0.9.0
BUILDLINK_PKGSRCDIR.orcus?=	../../converters/orcus

#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.endif	# ORCUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-orcus
