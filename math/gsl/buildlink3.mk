# $NetBSD: buildlink3.mk,v 1.1 2004/03/11 13:45:57 dmcmahill Exp $
#
# This Makefile fragment is included by packages that use gsl.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GSL_BUILDLINK3_MK:=	${GSL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gsl
.endif

.if !empty(GSL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		gsl
BUILDLINK_DEPENDS.gsl+=		gsl>=1.4
BUILDLINK_PKGSRCDIR.gsl?=	../../math/gsl

.endif # GSL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
