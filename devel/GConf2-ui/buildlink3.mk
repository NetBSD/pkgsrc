# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:09 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GCONF2_UI_BUILDLINK3_MK:=	${GCONF2_UI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	GConf2-ui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NGConf2-ui}
BUILDLINK_PACKAGES+=	GConf2-ui

.if !empty(GCONF2_UI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.GConf2-ui+=	GConf2-ui>=2.4.0.1nb1
BUILDLINK_PKGSRCDIR.GConf2-ui?=	../../devel/GConf2-ui

.include "../../devel/GConf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# GCONF2_UI_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
