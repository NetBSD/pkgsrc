# $NetBSD: buildlink3.mk,v 1.13 2008/09/06 20:54:32 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_BSDDB3_BUILDLINK3_MK:=	${PY_BSDDB3_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	py-bsddb3
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-bsddb3}
BUILDLINK_PACKAGES+=	py-bsddb3
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}py-bsddb3

.if !empty(PY_BSDDB3_BUILDLINK3_MK:M+)
.  include "../../mk/pthread.buildlink3.mk"
.  include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-bsddb3+=	${PYPKGPREFIX}-bsddb3>=4.3.3nb1
BUILDLINK_ABI_DEPENDS.py-bsddb3+=	${PYPKGPREFIX}-bsddb3>=4.6.4nb1
BUILDLINK_PKGSRCDIR.py-bsddb3?=	../../databases/py-bsddb3
.endif	# PY_BSDDB3_BUILDLINK3_MK

.include "../../databases/db4/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
