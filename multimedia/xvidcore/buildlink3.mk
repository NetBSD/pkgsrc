# $NetBSD: buildlink3.mk,v 1.4 2004/10/19 10:36:54 grant Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XVIDCORE_BUILDLINK3_MK:=	${XVIDCORE_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

# xvidcore is ONLY_FOR_PLATFORM -*-*-i386
.if ${MACHINE_ARCH} == "i386"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xvidcore
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxvidcore}
BUILDLINK_PACKAGES+=	xvidcore

.if !empty(XVIDCORE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xvidcore+=	xvidcore>=1.0.0
BUILDLINK_PKGSRCDIR.xvidcore?=	../../multimedia/xvidcore
.endif	# XVIDCORE_BUILDLINK3_MK

.endif	# MACHINE_ARCH == i386

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
