# $NetBSD: buildlink3.mk,v 1.2 2020/04/12 08:27:58 adam Exp $

BUILDLINK_TREE+=	mozjs68

.if !defined(MOZJS68_BUILDLINK3_MK)
MOZJS68_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mozjs68+=	mozjs68>=68.6.0
BUILDLINK_ABI_DEPENDS.mozjs68?=	mozjs68>=68.6.0nb1
BUILDLINK_PKGSRCDIR.mozjs68?=	../../lang/mozjs68

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif	# MOZJS68_BUILDLINK3_MK

BUILDLINK_TREE+=	-mozjs68
