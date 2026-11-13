# $NetBSD: buildlink3.mk,v 1.7 2026/11/13 14:39:29 pho Exp $

BUILDLINK_TREE+=	hjsmin

.if !defined(HJSMIN_BUILDLINK3_MK)
HJSMIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hjsmin+=	hjsmin>=0.2.1
BUILDLINK_ABI_DEPENDS.hjsmin+=	hjsmin>=0.2.1nb6
BUILDLINK_PKGSRCDIR.hjsmin?=	../../lang/hjsmin

.include "../../lang/hs-language-javascript/buildlink3.mk"
.endif	# HJSMIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hjsmin
