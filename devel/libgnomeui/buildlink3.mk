# $NetBSD: buildlink3.mk,v 1.4 2004/03/26 02:27:38 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMEUI_BUILDLINK3_MK:=	${LIBGNOMEUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomeui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomeui}
BUILDLINK_PACKAGES+=	libgnomeui

.if !empty(LIBGNOMEUI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgnomeui+=		libgnomeui>=2.4.0.1nb2
BUILDLINK_RECOMMENDED.libgnomeui?=	libgnomeui>=2.4.0.1nb6
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

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
