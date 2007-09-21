# $NetBSD: buildlink3.mk,v 1.19 2007/09/21 13:03:37 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBBONOBOUI_BUILDLINK3_MK:=	${LIBBONOBOUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libbonoboui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibbonoboui}
BUILDLINK_PACKAGES+=	libbonoboui
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libbonoboui

.if !empty(LIBBONOBOUI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libbonoboui+=		libbonoboui>=2.8.0
BUILDLINK_ABI_DEPENDS.libbonoboui+=	libbonoboui>=2.18.0nb1
BUILDLINK_PKGSRCDIR.libbonoboui?=	../../devel/libbonoboui
.endif	# LIBBONOBOUI_BUILDLINK3_MK

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
