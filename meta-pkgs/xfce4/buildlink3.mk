# $NetBSD: buildlink3.mk,v 1.3.2.1 2004/07/14 11:17:19 agc Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XFCE4_BUILDLINK3_MK:=	${XFCE4_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4}
BUILDLINK_PACKAGES+=	xfce4

.if !empty(XFCE4_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4+=	xfce4>=4.0.6
BUILDLINK_PKGSRCDIR.xfce4?=	../../meta-pkgs/xfce4
.endif	# XFCE4_BUILDLINK3_MK

.include "../../graphics/xfce4-iconbox/buildlink3.mk"
.include "../../print/xfce4-print/buildlink3.mk"
.include "../../sysutils/xfce4-fm/buildlink3.mk"
.include "../../wm/xfce4-wm/buildlink3.mk"
.include "../../x11/xfce4-desktop/buildlink3.mk"
.include "../../x11/xfce4-gtk2-engines/buildlink3.mk"
.include "../../x11/xfce4-utils/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../audio/xfce4-mixer/buildlink3.mk"
.include "../../sysutils/xfce4-fm-icons/buildlink3.mk"
.include "../../sysutils/xfce4-systray/buildlink3.mk"
.include "../../wm/xfce4-wm-themes/buildlink3.mk"
.include "../../x11/xfce4-themes/buildlink3.mk"
.include "../../x11/xfce4-toys/buildlink3.mk"
.include "../../x11/xfce4-trigger-launcher/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
