# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:27 pho Exp $

BUILDLINK_TREE+=	hs-regex-pcre

.if !defined(HS_REGEX_PCRE_BUILDLINK3_MK)
HS_REGEX_PCRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-pcre+=	hs-regex-pcre>=0.95.0
BUILDLINK_ABI_DEPENDS.hs-regex-pcre+=	hs-regex-pcre>=0.95.0.0nb2
BUILDLINK_PKGSRCDIR.hs-regex-pcre?=	../../textproc/hs-regex-pcre

.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.endif	# HS_REGEX_PCRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-pcre
