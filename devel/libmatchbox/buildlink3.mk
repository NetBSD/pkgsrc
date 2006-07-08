# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:10:45 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMATCHBOX_BUILDLINK3_MK:=	${LIBMATCHBOX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmatchbox
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmatchbox}
BUILDLINK_PACKAGES+=	libmatchbox
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libmatchbox

.if !empty(LIBMATCHBOX_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libmatchbox+=	libmatchbox>=1.4
BUILDLINK_ABI_DEPENDS.libmatchbox+=	libmatchbox>=1.7nb3
BUILDLINK_PKGSRCDIR.libmatchbox?=	../../devel/libmatchbox
.endif	# LIBMATCHBOX_BUILDLINK3_MK

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
