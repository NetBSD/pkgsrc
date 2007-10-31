# $NetBSD: buildlink3.mk,v 1.15 2007/10/31 20:07:51 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMECANVAS_BUILDLINK3_MK:=	${LIBGNOMECANVAS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomecanvas
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomecanvas}
BUILDLINK_PACKAGES+=	libgnomecanvas
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgnomecanvas

.if !empty(LIBGNOMECANVAS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgnomecanvas+=	libgnomecanvas>=2.8.0
BUILDLINK_ABI_DEPENDS.libgnomecanvas+=	libgnomecanvas>=2.14.0nb1
BUILDLINK_PKGSRCDIR.libgnomecanvas?=	../../graphics/libgnomecanvas
.endif	# LIBGNOMECANVAS_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
