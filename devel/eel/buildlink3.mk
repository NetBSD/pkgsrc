# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:12 joerg Exp $

BUILDLINK_TREE+=	eel

.if !defined(EEL_BUILDLINK3_MK)
EEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eel+=	eel>=2.10.0
BUILDLINK_ABI_DEPENDS.eel?=	eel>=2.20.0nb1
BUILDLINK_PKGSRCDIR.eel?=	../../devel/eel

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # EEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-eel
