# $NetBSD: buildlink3.mk,v 1.16 2006/07/08 23:10:44 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMEUI_BUILDLINK3_MK:=	${LIBGNOMEUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomeui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomeui}
BUILDLINK_PACKAGES+=	libgnomeui
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgnomeui

.if !empty(LIBGNOMEUI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgnomeui+=		libgnomeui>=2.8.0
BUILDLINK_ABI_DEPENDS.libgnomeui+=	libgnomeui>=2.14.1nb1
BUILDLINK_PKGSRCDIR.libgnomeui?=	../../devel/libgnomeui
.endif	# LIBGNOMEUI_BUILDLINK3_MK

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
