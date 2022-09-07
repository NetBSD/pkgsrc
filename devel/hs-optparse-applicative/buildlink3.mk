# $NetBSD: buildlink3.mk,v 1.8 2022/09/07 06:50:48 pho Exp $

BUILDLINK_TREE+=	hs-optparse-applicative

.if !defined(HS_OPTPARSE_APPLICATIVE_BUILDLINK3_MK)
HS_OPTPARSE_APPLICATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-optparse-applicative+=	hs-optparse-applicative>=0.17.0
BUILDLINK_ABI_DEPENDS.hs-optparse-applicative+=	hs-optparse-applicative>=0.17.0.0nb3
BUILDLINK_PKGSRCDIR.hs-optparse-applicative?=	../../devel/hs-optparse-applicative

.include "../../textproc/hs-ansi-wl-pprint/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_OPTPARSE_APPLICATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-optparse-applicative
