# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:50 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EPEG_BUILDLINK3_MK:=	${EPEG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	epeg
.endif

BUILDLINK_PACKAGES+=	epeg
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}epeg

.if !empty(EPEG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.epeg+=	epeg>=0.9.0
BUILDLINK_PKGSRCDIR.epeg?=	../../graphics/epeg
.endif	# EPEG_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
