# $NetBSD: buildlink3.mk,v 1.5 2004/04/01 18:23:21 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBBONOBOUI_BUILDLINK3_MK:=	${LIBBONOBOUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libbonoboui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibbonoboui}
BUILDLINK_PACKAGES+=	libbonoboui

.if !empty(LIBBONOBOUI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libbonoboui+=		libbonoboui>=2.6.0
BUILDLINK_PKGSRCDIR.libbonoboui?=	../../devel/libbonoboui
.endif	# LIBBONOBOUI_BUILDLINK3_MK

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
