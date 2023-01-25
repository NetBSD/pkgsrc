# $NetBSD: buildlink3.mk,v 1.4 2023/01/25 16:23:22 pho Exp $

BUILDLINK_TREE+=	hs-hslua-marshalling

.if !defined(HS_HSLUA_MARSHALLING_BUILDLINK3_MK)
HS_HSLUA_MARSHALLING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-marshalling+=	hs-hslua-marshalling>=2.2.1
BUILDLINK_ABI_DEPENDS.hs-hslua-marshalling+=	hs-hslua-marshalling>=2.2.1
BUILDLINK_PKGSRCDIR.hs-hslua-marshalling?=	../../lang/hs-hslua-marshalling

.include "../../lang/hs-hslua-core/buildlink3.mk"
.endif	# HS_HSLUA_MARSHALLING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-marshalling
