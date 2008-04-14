# $NetBSD: buildlink3.mk,v 1.11 2008/04/14 11:35:50 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ENCHANT_BUILDLINK3_MK:=	${ENCHANT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	enchant
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nenchant}
BUILDLINK_PACKAGES+=	enchant
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}enchant

.if !empty(ENCHANT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.enchant+=	enchant>=1.1.3
BUILDLINK_ABI_DEPENDS.enchant+=	enchant>=1.1.6nb1
BUILDLINK_PKGSRCDIR.enchant?=	../../textproc/enchant
.endif	# ENCHANT_BUILDLINK3_MK

# spelling libraries are loaded dynamically and do not need
# to be included here
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
