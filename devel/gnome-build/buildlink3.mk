# $NetBSD: buildlink3.mk,v 1.1 2007/01/07 12:04:08 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_BUILD_BUILDLINK3_MK:=	${GNOME_BUILD_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gnome-build
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-build}
BUILDLINK_PACKAGES+=	gnome-build
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-build

.if ${GNOME_BUILD_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gnome-build+=	gnome-build>=0.1.3
BUILDLINK_PKGSRCDIR.gnome-build?=	../../devel/gnome-build
.endif	# GNOME_BUILD_BUILDLINK3_MK

.include "../../devel/gal/buildlink3.mk"
.include "../../devel/gdl/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
