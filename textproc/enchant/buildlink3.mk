# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:15 jlam Exp $

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
.endif	# ENCHANT_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
