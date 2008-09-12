# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/09/12 13:18:26 jmcneill Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PTLIB_BUILDLINK3_MK:=	${PTLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ptlib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nptlib}
BUILDLINK_PACKAGES+=	ptlib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ptlib

.if !empty(PTLIB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.ptlib+=	ptlib>=2.3.0
BUILDLINK_ABI_DEPENDS.ptlib?=	ptlib>=2.3.0
BUILDLINK_PKGSRCDIR.ptlib?=	../../devel/ptlib
.endif	# PTLIB_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
