# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 22:39:10 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGLADE_BUILDLINK3_MK:=	${LIBGLADE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libglade
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibglade}
BUILDLINK_PACKAGES+=	libglade
BUILDLINK_ORDER+=	libglade

.if !empty(LIBGLADE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libglade+=	libglade>=0.17nb5
BUILDLINK_ABI_DEPENDS.libglade+=	libglade>=0.17nb9
BUILDLINK_PKGSRCDIR.libglade?=	../../devel/libglade
.endif	# LIBGLADE_BUILDLINK3_MK

.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
