# $NetBSD: buildlink3.mk,v 1.24 2009/08/26 19:57:04 sno Exp $

BUILDLINK_TREE+=	xfce4-mixer

.if !defined(XFCE4_MIXER_BUILDLINK3_MK)
XFCE4_MIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-mixer+=	xfce4-mixer>=4.4.3nb1
BUILDLINK_ABI_DEPENDS.xfce4-mixer?=	xfce4-mixer>=4.4.3nb2
BUILDLINK_PKGSRCDIR.xfce4-mixer?=	../../audio/xfce4-mixer

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_MIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-mixer
