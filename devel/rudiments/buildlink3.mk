# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:08:53 joerg Exp $
#
# This Makefile fragment is included by packages that use rudiments.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RUDIMENTS_BUILDLINK3_MK:=	${RUDIMENTS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	rudiments
.endif

.if !empty(RUDIMENTS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			rudiments
BUILDLINK_DEPENDS.rudiments+=		rudiments>=0.25.1
BUILDLINK_RECOMMENDED.rudiments+=	rudiments>=0.28.2nb1
BUILDLINK_PKGSRCDIR.rudiments?=		../../devel/rudiments

.endif # RUDIMENTS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
