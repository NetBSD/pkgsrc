# $NetBSD: buildlink3.mk,v 1.15 2012/05/07 01:53:39 dholland Exp $

BUILDLINK_TREE+=	uim

.if !defined(UIM_BUILDLINK3_MK)
UIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uim+=	uim>=1.5.1
BUILDLINK_ABI_DEPENDS.uim+=	uim>=1.6.1nb1
BUILDLINK_PKGSRCDIR.uim?=	../../inputmethod/uim

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgcroots/buildlink3.mk"
.endif # UIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-uim
