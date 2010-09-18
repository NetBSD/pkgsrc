# $NetBSD: buildlink3.mk,v 1.13 2010/09/18 03:08:31 obache Exp $

BUILDLINK_TREE+=	uim

.if !defined(UIM_BUILDLINK3_MK)
UIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uim+=	uim>=1.5.1
BUILDLINK_ABI_DEPENDS.uim?=	uim>=1.6.0
BUILDLINK_PKGSRCDIR.uim?=	../../inputmethod/uim

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgcroots/buildlink3.mk"
.endif # UIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-uim
