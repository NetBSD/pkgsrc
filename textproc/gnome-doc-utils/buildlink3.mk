# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/03/22 16:24:11 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_DOC_UTILS_BUILDLINK3_MK:=	${GNOME_DOC_UTILS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-doc-utils
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-doc-utils}
BUILDLINK_PACKAGES+=	gnome-doc-utils

.if !empty(GNOME_DOC_UTILS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-doc-utils+=	gnome-doc-utils>=0.1.3
BUILDLINK_PKGSRCDIR.gnome-doc-utils?=	../../textproc/gnome-doc-utils
.endif	# GNOME_DOC_UTILS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
