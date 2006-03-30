# $NetBSD: buildlink3.mk,v 1.2 2006/03/30 21:30:25 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
POPPLER_GLIB_BUILDLINK3_MK:=	${POPPLER_GLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	poppler-glib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npoppler-glib}
BUILDLINK_PACKAGES+=	poppler-glib

.if !empty(POPPLER_GLIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.poppler-glib+=	poppler-glib>=0.5.1
BUILDLINK_PKGSRCDIR.poppler-glib?=	../../print/poppler-glib
.endif	# POPPLER_GLIB_BUILDLINK3_MK

.include "../../print/poppler/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
