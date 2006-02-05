# $NetBSD: buildlink3.mk,v 1.4 2006/02/05 23:09:34 joerg Exp $
#
# This file was created automatically using createbuildlink-3.4.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBEXIF_GTK_BUILDLINK3_MK:=	${LIBEXIF_GTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libexif-gtk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibexif-gtk}
BUILDLINK_PACKAGES+=	libexif-gtk

.if !empty(LIBEXIF_GTK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libexif-gtk+=	libexif-gtk>=0.3.3nb7
BUILDLINK_RECOMMENDED.libexif-gtk+=	libexif-gtk>=0.3.5nb3
BUILDLINK_PKGSRCDIR.libexif-gtk?=	../../graphics/libexif-gtk
.endif	# LIBEXIF_GTK_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
