# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 09:10:15 xtraeme Exp $
#
# This Makefile fragment is included by packages that use jasper.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
JASPER_BUILDLINK3_MK:=	${JASPER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	jasper
.endif

.if !empty(JASPER_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			jasper
BUILDLINK_DEPENDS.jasper+=		jasper>=1.600.0
BUILDLINK_PKGSRCDIR.jasper?=		../../graphics/jasper

.include "../../graphics/jpeg/buildlink3.mk"

.endif # JASPER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
