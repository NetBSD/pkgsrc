# $NetBSD: buildlink3.mk,v 1.5 2023/10/29 07:18:44 pho Exp $

BUILDLINK_TREE+=	hs-with-utf8

.if !defined(HS_WITH_UTF8_BUILDLINK3_MK)
HS_WITH_UTF8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-with-utf8+=	hs-with-utf8>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-with-utf8+=	hs-with-utf8>=1.0.2.4
BUILDLINK_PKGSRCDIR.hs-with-utf8?=	../../devel/hs-with-utf8

.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.endif	# HS_WITH_UTF8_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-with-utf8
