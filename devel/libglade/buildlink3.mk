# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:10 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGLADE_BUILDLINK3_MK:=	${LIBGLADE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libglade
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibglade}
BUILDLINK_PACKAGES+=	libglade

.if !empty(LIBGLADE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libglade+=	libglade>=0.17nb5
BUILDLINK_PKGSRCDIR.libglade?=	../../devel/libglade
.endif	# LIBGLADE_BUILDLINK3_MK

.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
