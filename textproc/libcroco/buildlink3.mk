# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:40 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBCROCO_BUILDLINK3_MK:=	${LIBCROCO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libcroco
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibcroco}
BUILDLINK_PACKAGES+=	libcroco

.if !empty(LIBCROCO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libcroco+=	libcroco>=0.4.0
BUILDLINK_PKGSRCDIR.libcroco?=	../../textproc/libcroco

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.endif	# LIBCROCO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
