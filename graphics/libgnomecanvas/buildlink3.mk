# $NetBSD: buildlink3.mk,v 1.6 2004/10/03 00:14:55 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMECANVAS_BUILDLINK3_MK:=	${LIBGNOMECANVAS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomecanvas
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomecanvas}
BUILDLINK_PACKAGES+=	libgnomecanvas

.if !empty(LIBGNOMECANVAS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgnomecanvas+=	libgnomecanvas>=2.8.0
BUILDLINK_RECOMMENDED.libgnomecanvas+=	libgnomecanvas>=2.8.0nb1
BUILDLINK_PKGSRCDIR.libgnomecanvas?=	../../graphics/libgnomecanvas
.endif	# LIBGNOMECANVAS_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
