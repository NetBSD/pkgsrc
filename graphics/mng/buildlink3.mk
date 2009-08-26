# $NetBSD: buildlink3.mk,v 1.12 2009/08/26 19:56:39 sno Exp $

BUILDLINK_TREE+=	mng

.if !defined(MNG_BUILDLINK3_MK)
MNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mng+=		mng>=1.0.0
BUILDLINK_ABI_DEPENDS.mng+=	mng>=1.0.10nb1
BUILDLINK_PKGSRCDIR.mng?=	../../graphics/mng

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.endif # MNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-mng
