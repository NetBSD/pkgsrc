# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 22:39:05 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_METAKIT_BUILDLINK3_MK:=	${PY_METAKIT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pymetakit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npymetakit}
BUILDLINK_PACKAGES+=	pymetakit
BUILDLINK_ORDER+=	pymetakit

.if !empty(PY_METAKIT_BUILDLINK3_MK:M+)
.include "../../lang/python/pyversion.mk"
BUILDLINK_API_DEPENDS.pymetakit+=	${PYPKGPREFIX}-metakit-[0-9]*
BUILDLINK_ABI_DEPENDS.pymetakit+=	${PYPKGPREFIX}-metakit>=2.4.9.3nb2
BUILDLINK_PKGSRCDIR.pymetakit?=	../../databases/py-metakit
.endif	# PY_METAKIT_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
