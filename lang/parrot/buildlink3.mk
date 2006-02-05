# $NetBSD: buildlink3.mk,v 1.2 2006/02/05 23:09:47 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PARROT_BUILDLINK3_MK:=	${PARROT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	parrot
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nparrot}
BUILDLINK_PACKAGES+=	parrot

.if !empty(PARROT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.parrot+=		parrot>=0.4.0
BUILDLINK_RECOMMENDED.parrot?=		parrot>=0.4.1nb1
BUILDLINK_PKGSRCDIR.parrot?=		../../lang/parrot
.endif	# PARROT_BUILDLINK3_MK

.include "../../textproc/icu/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
