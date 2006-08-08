# $NetBSD: buildlink3.mk,v 1.10 2006/08/08 16:55:18 drochner Exp $

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
BUILDLINK_ABI_DEPENDS.py-bsddb3+=	${PYPKGPREFIX}-bsddb3>=4.3.3nb2
BUILDLINK_PKGSRCDIR.py-bsddb3?=	../../databases/py-bsddb3
.endif	# PY_BSDDB3_BUILDLINK3_MK

.include "../../databases/db4/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
