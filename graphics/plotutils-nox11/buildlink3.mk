# $NetBSD: buildlink3.mk,v 1.1 2004/04/17 01:14:19 snj Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PLOTUTILS_NOX11_BUILDLINK3_MK:=	${PLOTUTILS_NOX11_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	plotutils-nox11
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nplotutils-nox11}
BUILDLINK_PACKAGES+=	plotutils-nox11

.if !empty(PLOTUTILS_NOX11_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.plotutils-nox11+=	plotutils-nox11>=2.4.1
BUILDLINK_PKGSRCDIR.plotutils-nox11?=	../../graphics/plotutils-nox11
.endif	# PLOTUTILS_NOX11_BUILDLINK3_MK

.include "../../graphics/png/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
