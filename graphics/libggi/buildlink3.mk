# $NetBSD: buildlink3.mk,v 1.1 2004/04/16 17:39:32 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGGI_BUILDLINK3_MK:=	${LIBGGI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libggi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibggi}
BUILDLINK_PACKAGES+=	libggi

.if !empty(LIBGGI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libggi+=	libggi>=2.0.4
BUILDLINK_PKGSRCDIR.libggi?=	../../graphics/libggi
.endif	# LIBGGI_BUILDLINK3_MK

USE_X11=    yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/libgii/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
