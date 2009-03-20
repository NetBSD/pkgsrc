# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:12 joerg Exp $

BUILDLINK_TREE+=	eet

.if !defined(EET_BUILDLINK3_MK)
EET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eet+=	eet>=1.0.1
BUILDLINK_PKGSRCDIR.eet?=	../../devel/eet

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.endif # EET_BUILDLINK3_MK

BUILDLINK_TREE+=	-eet
