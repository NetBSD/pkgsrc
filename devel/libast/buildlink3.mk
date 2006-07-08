# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:10:43 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBAST_BUILDLINK3_MK:=	${LIBAST_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libast
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibast}
BUILDLINK_PACKAGES+=	libast
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libast

.if !empty(LIBAST_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libast+=	libast>=0.5nb5
BUILDLINK_ABI_DEPENDS.libast+=	libast>=0.6.1nb3
BUILDLINK_PKGSRCDIR.libast?=	../../devel/libast
.endif	# LIBAST_BUILDLINK3_MK

.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
