# $NetBSD: buildlink3.mk,v 1.1 2020/04/06 04:58:42 wiz Exp $

BUILDLINK_TREE+=	mozjs68

.if !defined(MOZJS68_BUILDLINK3_MK)
MOZJS68_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mozjs68+=	mozjs68>=68.6.0
BUILDLINK_PKGSRCDIR.mozjs68?=	../../lang/mozjs68

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif	# MOZJS68_BUILDLINK3_MK

BUILDLINK_TREE+=	-mozjs68
