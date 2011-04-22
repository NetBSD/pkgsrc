# $NetBSD: buildlink3.mk,v 1.9 2011/04/22 13:41:54 obache Exp $

BUILDLINK_TREE+=	recode

.if !defined(RECODE_BUILDLINK3_MK)
RECODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.recode+=	recode>=3.6nb1
BUILDLINK_ABI_DEPENDS.recode+=	recode>=3.6nb5
BUILDLINK_PKGSRCDIR.recode?=	../../converters/recode

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # RECODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-recode
