# $NetBSD: buildlink3.mk,v 1.4 2024/05/09 01:32:23 pho Exp $

BUILDLINK_TREE+=	hs-hslua-typing

.if !defined(HS_HSLUA_TYPING_BUILDLINK3_MK)
HS_HSLUA_TYPING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-typing+=	hs-hslua-typing>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-hslua-typing+=	hs-hslua-typing>=0.1.1nb1
BUILDLINK_PKGSRCDIR.hs-hslua-typing?=	../../lang/hs-hslua-typing

.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.endif	# HS_HSLUA_TYPING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-typing
