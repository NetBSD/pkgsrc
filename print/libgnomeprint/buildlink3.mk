# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 02:34:55 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libgnomeprint.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGNOMEPRINT_BUILDLINK3_MK:=	${LIBGNOMEPRINT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomeprint
.endif

.if !empty(LIBGNOMEPRINT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgnomeprint
BUILDLINK_DEPENDS.libgnomeprint+=	libgnomeprint>=2.4.2nb1
BUILDLINK_PKGSRCDIR.libgnomeprint?=	../../print/libgnomeprint

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"

.include "../../mk/bsd.prefs.mk"

.  if defined(USE_CUPS) && !empty(USE_CUPS:M[Yy][Ee][Ss])
.    include "../../print/cups/buildlink3.mk"
.  endif

.endif # LIBGNOMEPRINT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
