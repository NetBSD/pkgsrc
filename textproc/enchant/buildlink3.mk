# $NetBSD: buildlink3.mk,v 1.6 2006/02/05 23:11:01 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ENCHANT_BUILDLINK3_MK:=	${ENCHANT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	enchant
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nenchant}
BUILDLINK_PACKAGES+=	enchant

.if !empty(ENCHANT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.enchant+=	enchant>=1.1.3
BUILDLINK_RECOMMENDED.enchant+=	enchant>=1.1.6nb1
BUILDLINK_PKGSRCDIR.enchant?=	../../textproc/enchant
.endif	# ENCHANT_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
