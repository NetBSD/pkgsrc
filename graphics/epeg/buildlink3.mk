# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/12/28 21:54:35 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EPEG_BUILDLINK3_MK:=	${EPEG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	epeg
.endif

BUILDLINK_PACKAGES+=	epeg

.if !empty(EPEG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.epeg+=	epeg>=0.9.0
BUILDLINK_PKGSRCDIR.epeg?=	../../graphics/epeg
.endif	# EPEG_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
