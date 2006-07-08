# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:10:52 jlam Exp $
#
# This file was created automatically using createbuildlink-3.4.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBEXIF_GTK_BUILDLINK3_MK:=	${LIBEXIF_GTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libexif-gtk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibexif-gtk}
BUILDLINK_PACKAGES+=	libexif-gtk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libexif-gtk

.if !empty(LIBEXIF_GTK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libexif-gtk+=	libexif-gtk>=0.3.3nb7
BUILDLINK_ABI_DEPENDS.libexif-gtk+=	libexif-gtk>=0.3.5nb4
BUILDLINK_PKGSRCDIR.libexif-gtk?=	../../graphics/libexif-gtk
.endif	# LIBEXIF_GTK_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
