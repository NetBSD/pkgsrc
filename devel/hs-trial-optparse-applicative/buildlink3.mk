# $NetBSD: buildlink3.mk,v 1.2 2024/05/09 01:32:16 pho Exp $

BUILDLINK_TREE+=	hs-trial-optparse-applicative

.if !defined(HS_TRIAL_OPTPARSE_APPLICATIVE_BUILDLINK3_MK)
HS_TRIAL_OPTPARSE_APPLICATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-trial-optparse-applicative+=	hs-trial-optparse-applicative>=0.0.0
BUILDLINK_ABI_DEPENDS.hs-trial-optparse-applicative+=	hs-trial-optparse-applicative>=0.0.0.0nb1
BUILDLINK_PKGSRCDIR.hs-trial-optparse-applicative?=	../../devel/hs-trial-optparse-applicative

.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-trial/buildlink3.mk"
.endif	# HS_TRIAL_OPTPARSE_APPLICATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-trial-optparse-applicative
