# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 22:39:35 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PYREPORTLAB_BUILDLINK3_MK:=	${PYREPORTLAB_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyreportlab
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyreportlab}
BUILDLINK_PACKAGES+=	pyreportlab
BUILDLINK_ORDER+=	pyreportlab

.if !empty(PYREPORTLAB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.pyreportlab+=		${PYPKGPREFIX}-reportlab-[0-9]*
BUILDLINK_ABI_DEPENDS.pyreportlab?=	${PYPKGPREFIX}-reportlab>=1.20nb2
BUILDLINK_PKGSRCDIR.pyreportlab?=	../../print/py-reportlab
.endif	# PYREPORTLAB_BUILDLINK3_MK

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
