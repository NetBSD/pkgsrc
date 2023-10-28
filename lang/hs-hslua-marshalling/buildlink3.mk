# $NetBSD: buildlink3.mk,v 1.7 2023/10/28 20:10:44 pho Exp $

BUILDLINK_TREE+=	hs-hslua-marshalling

.if !defined(HS_HSLUA_MARSHALLING_BUILDLINK3_MK)
HS_HSLUA_MARSHALLING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-marshalling+=	hs-hslua-marshalling>=2.3.0
BUILDLINK_ABI_DEPENDS.hs-hslua-marshalling+=	hs-hslua-marshalling>=2.3.0
BUILDLINK_PKGSRCDIR.hs-hslua-marshalling?=	../../lang/hs-hslua-marshalling

.include "../../lang/hs-hslua-core/buildlink3.mk"
.endif	# HS_HSLUA_MARSHALLING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-marshalling
