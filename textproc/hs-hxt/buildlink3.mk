# $NetBSD: buildlink3.mk,v 1.8 2023/10/09 04:54:51 pho Exp $

BUILDLINK_TREE+=	hs-hxt

.if !defined(HS_HXT_BUILDLINK3_MK)
HS_HXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt+=	hs-hxt>=9.3.1
BUILDLINK_ABI_DEPENDS.hs-hxt+=	hs-hxt>=9.3.1.22nb6
BUILDLINK_PKGSRCDIR.hs-hxt?=	../../textproc/hs-hxt

.include "../../textproc/hs-hxt-charproperties/buildlink3.mk"
.include "../../textproc/hs-hxt-regex-xmlschema/buildlink3.mk"
.include "../../textproc/hs-hxt-unicode/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.endif	# HS_HXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt
