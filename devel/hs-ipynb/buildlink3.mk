# $NetBSD: buildlink3.mk,v 1.1 2020/01/16 13:52:56 pho Exp $

BUILDLINK_TREE+=	hs-ipynb

.if !defined(HS_IPYNB_BUILDLINK3_MK)
HS_IPYNB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ipynb+=	hs-ipynb>=0.1
BUILDLINK_ABI_DEPENDS.hs-ipynb+=	hs-ipynb>=0.1
BUILDLINK_PKGSRCDIR.hs-ipynb?=		../../devel/hs-ipynb

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_IPYNB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ipynb
