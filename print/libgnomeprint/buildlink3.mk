# $NetBSD: buildlink3.mk,v 1.5 2004/09/21 16:49:04 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMEPRINT_BUILDLINK3_MK:=	${LIBGNOMEPRINT_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomeprint
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomeprint}
BUILDLINK_PACKAGES+=	libgnomeprint

.if !empty(LIBGNOMEPRINT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgnomeprint+=	libgnomeprint>=2.8.0
BUILDLINK_PKGSRCDIR.libgnomeprint?=	../../print/libgnomeprint
.endif	# LIBGNOMEPRINT_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"

.if defined(USE_CUPS) && !empty(USE_CUPS:M[Yy][Ee][Ss])
.  include "../../print/cups/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
