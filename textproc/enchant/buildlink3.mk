# $NetBSD: buildlink3.mk,v 1.1 2004/02/15 23:25:38 wiz Exp $
#
# This Makefile fragment is included by packages that use enchant.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ENCHANT_BUILDLINK3_MK:=	${ENCHANT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	enchant
.endif

.if !empty(ENCHANT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			enchant
BUILDLINK_DEPENDS.enchant+=		enchant>=1.1.3
BUILDLINK_PKGSRCDIR.enchant?=		../../textproc/enchant

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"

.endif # ENCHANT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
