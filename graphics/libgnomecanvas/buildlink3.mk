# $NetBSD: buildlink3.mk,v 1.5 2004/09/21 16:46:45 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMECANVAS_BUILDLINK3_MK:=	${LIBGNOMECANVAS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomecanvas
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomecanvas}
BUILDLINK_PACKAGES+=	libgnomecanvas

.if !empty(LIBGNOMECANVAS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgnomecanvas+=	libgnomecanvas>=2.8.0
BUILDLINK_PKGSRCDIR.libgnomecanvas?=	../../graphics/libgnomecanvas
.endif	# LIBGNOMECANVAS_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
