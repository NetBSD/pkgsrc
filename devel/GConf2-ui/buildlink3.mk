# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 00:53:57 xtraeme Exp $
#
# This Makefile fragment is included by packages that use GConf2-ui.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCONF2_UI_BUILDLINK3_MK:=	${GCONF2_UI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	GConf2-ui
.endif

.if !empty(GCONF2_UI_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			GConf2-ui
BUILDLINK_DEPENDS.GConf2-ui+=		GConf2-ui>=2.4.0.1nb1
BUILDLINK_PKGSRCDIR.GConf2-ui?=		../../devel/GConf2-ui

.include "../../devel/GConf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # GCONF2_UI_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
