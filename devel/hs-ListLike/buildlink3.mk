# $NetBSD: buildlink3.mk,v 1.6 2022/08/20 08:08:13 wiz Exp $

BUILDLINK_TREE+=	hs-ListLike

.if !defined(HS_LISTLIKE_BUILDLINK3_MK)
HS_LISTLIKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ListLike+=	hs-ListLike>=4.7.6
BUILDLINK_ABI_DEPENDS.hs-ListLike+=	hs-ListLike>=4.7.6nb3
BUILDLINK_PKGSRCDIR.hs-ListLike?=	../../devel/hs-ListLike

.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-fmlist/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_LISTLIKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ListLike
