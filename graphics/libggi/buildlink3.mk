# $NetBSD: buildlink3.mk,v 1.7 2006/04/06 06:22:04 reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGGI_BUILDLINK3_MK:=	${LIBGGI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libggi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibggi}
BUILDLINK_PACKAGES+=	libggi

.if !empty(LIBGGI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libggi+=	libggi>=2.1.0
BUILDLINK_ABI_DEPENDS.libggi?=	libggi>=2.1.1nb1
BUILDLINK_PKGSRCDIR.libggi?=	../../graphics/libggi
.endif	# LIBGGI_BUILDLINK3_MK

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/libgii/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
