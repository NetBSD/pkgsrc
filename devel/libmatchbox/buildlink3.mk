# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:13:30 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMATCHBOX_BUILDLINK3_MK:=	${LIBMATCHBOX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmatchbox
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmatchbox}
BUILDLINK_PACKAGES+=	libmatchbox

.if !empty(LIBMATCHBOX_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libmatchbox+=	libmatchbox>=1.4
BUILDLINK_RECOMMENDED.libmatchbox+=	libmatchbox>=1.4nb1
BUILDLINK_PKGSRCDIR.libmatchbox?=	../../devel/libmatchbox
.endif	# LIBMATCHBOX_BUILDLINK3_MK

.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
