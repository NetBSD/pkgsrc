# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 02:12:36 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libbonoboui.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBBONOBOUI_BUILDLINK3_MK:=	${LIBBONOBOUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libbonoboui
.endif

.if !empty(LIBBONOBOUI_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libbonoboui
BUILDLINK_DEPENDS.libbonoboui+=		libbonoboui>=2.4.1nb2
BUILDLINK_PKGSRCDIR.libbonoboui?=	../../devel/libbonoboui

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # LIBBONOBOUI_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
