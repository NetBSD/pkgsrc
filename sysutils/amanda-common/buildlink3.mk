# $NetBSD: buildlink3.mk,v 1.6 2006/02/05 23:10:48 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
AMANDA_COMMON_BUILDLINK3_MK:=	${AMANDA_COMMON_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	amanda-common
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Namanda-common}
BUILDLINK_PACKAGES+=	amanda-common

.if !empty(AMANDA_COMMON_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.amanda-common+=	amanda-common>=2.4.4p4nb2
BUILDLINK_RECOMMENDED.amanda-common+=	amanda-common>=2.4.4p4nb3
BUILDLINK_PKGSRCDIR.amanda-common?=	../../sysutils/amanda-common
.endif	# AMANDA_COMMON_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
