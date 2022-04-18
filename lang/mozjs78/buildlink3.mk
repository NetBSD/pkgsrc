# $NetBSD: buildlink3.mk,v 1.5 2022/04/18 19:09:55 adam Exp $

BUILDLINK_TREE+=	mozjs78

.if !defined(MOZJS78_BUILDLINK3_MK)
MOZJS78_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mozjs78+=	mozjs78>=78.3.0
BUILDLINK_ABI_DEPENDS.mozjs78?=	mozjs78>=78.15.0nb2
BUILDLINK_PKGSRCDIR.mozjs78?=	../../lang/mozjs78

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif	# MOZJS78_BUILDLINK3_MK

BUILDLINK_TREE+=	-mozjs78
