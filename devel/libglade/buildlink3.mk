# $NetBSD: buildlink3.mk,v 1.1 2004/02/15 12:35:11 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGLADE_BUILDLINK3_MK:=	${LIBGLADE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libglade
.endif

.if !empty(LIBGLADE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		libglade
BUILDLINK_DEPENDS.libglade+=	libglade>=0.17nb5
BUILDLINK_PKGSRCDIR.libglade?=	../../devel/libglade

.  include "../../textproc/libxml/buildlink3.mk"
.  include "../../x11/gnome-libs/buildlink3.mk"
.endif # LIBGLADE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
