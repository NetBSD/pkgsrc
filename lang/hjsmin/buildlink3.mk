# $NetBSD: buildlink3.mk,v 1.1 2023/11/01 03:14:49 pho Exp $

BUILDLINK_TREE+=	hjsmin

.if !defined(HJSMIN_BUILDLINK3_MK)
HJSMIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hjsmin+=	hjsmin>=0.2.1
BUILDLINK_ABI_DEPENDS.hjsmin+=	hjsmin>=0.2.1
BUILDLINK_PKGSRCDIR.hjsmin?=	../../lang/hjsmin

.include "../../lang/hs-language-javascript/buildlink3.mk"
.endif	# HJSMIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hjsmin
