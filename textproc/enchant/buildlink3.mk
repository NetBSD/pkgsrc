# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:40 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ENCHANT_BUILDLINK3_MK:=	${ENCHANT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	enchant
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nenchant}
BUILDLINK_PACKAGES+=	enchant

.if !empty(ENCHANT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.enchant+=	enchant>=1.1.3
BUILDLINK_PKGSRCDIR.enchant?=	../../textproc/enchant

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"

.endif	# ENCHANT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
