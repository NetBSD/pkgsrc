# $NetBSD: buildlink3.mk,v 1.16 2006/07/08 23:11:11 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBCROCO_BUILDLINK3_MK:=	${LIBCROCO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libcroco
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibcroco}
BUILDLINK_PACKAGES+=	libcroco
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libcroco

.if !empty(LIBCROCO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libcroco+=	libcroco>=0.6.0
BUILDLINK_ABI_DEPENDS.libcroco+=	libcroco>=0.6.1nb1
BUILDLINK_PKGSRCDIR.libcroco?=	../../textproc/libcroco
.endif	# LIBCROCO_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
