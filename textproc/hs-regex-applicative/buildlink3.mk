# $NetBSD: buildlink3.mk,v 1.4 2023/10/09 04:54:53 pho Exp $

BUILDLINK_TREE+=	hs-regex-applicative

.if !defined(HS_REGEX_APPLICATIVE_BUILDLINK3_MK)
HS_REGEX_APPLICATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-applicative+=	hs-regex-applicative>=0.3.4
BUILDLINK_ABI_DEPENDS.hs-regex-applicative+=	hs-regex-applicative>=0.3.4nb3
BUILDLINK_PKGSRCDIR.hs-regex-applicative?=	../../textproc/hs-regex-applicative

.include "../../devel/hs-filtrable/buildlink3.mk"
.endif	# HS_REGEX_APPLICATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-applicative
