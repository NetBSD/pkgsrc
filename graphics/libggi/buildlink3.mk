# $NetBSD: buildlink3.mk,v 1.3 2004/10/03 00:14:55 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGGI_BUILDLINK3_MK:=	${LIBGGI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libggi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibggi}
BUILDLINK_PACKAGES+=	libggi

.if !empty(LIBGGI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libggi+=	libggi>=2.0.6
BUILDLINK_RECOMMENDED.libggi+=	libggi>=2.0.6nb1
BUILDLINK_PKGSRCDIR.libggi?=	../../graphics/libggi
.endif	# LIBGGI_BUILDLINK3_MK

USE_X11=    yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/libgii/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
