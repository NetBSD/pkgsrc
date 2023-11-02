# $NetBSD: buildlink3.mk,v 1.12 2023/11/02 06:36:49 pho Exp $

BUILDLINK_TREE+=	hs-optparse-applicative

.if !defined(HS_OPTPARSE_APPLICATIVE_BUILDLINK3_MK)
HS_OPTPARSE_APPLICATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-optparse-applicative+=	hs-optparse-applicative>=0.18.1
BUILDLINK_ABI_DEPENDS.hs-optparse-applicative+=	hs-optparse-applicative>=0.18.1.0nb1
BUILDLINK_PKGSRCDIR.hs-optparse-applicative?=	../../devel/hs-optparse-applicative

.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../textproc/hs-prettyprinter-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_OPTPARSE_APPLICATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-optparse-applicative
