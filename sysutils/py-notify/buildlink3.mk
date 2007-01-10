# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/01/10 10:40:52 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_NOTIFY_BUILDLINK3_MK:=	${PY_NOTIFY_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	py-notify
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-notify}
BUILDLINK_PACKAGES+=	py-notify
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}py-notify

.if ${PY_NOTIFY_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.py-notify+=	${PYPKGPREFIX}-notify>=0.1.1
BUILDLINK_PKGSRCDIR.py-notify?=	../../sysutils/py-notify
.endif	# PY_NOTIFY_BUILDLINK3_MK

.include "../../x11/py-gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
