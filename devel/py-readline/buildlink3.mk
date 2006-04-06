# $NetBSD: buildlink3.mk,v 1.3 2006/04/06 06:21:55 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PYREADLINE_BUILDLINK3_MK:=	${PYREADLINE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyreadline
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyreadline}
BUILDLINK_PACKAGES+=	pyreadline

.if !empty(PYREADLINE_BUILDLINK3_MK:M+)

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyreadline+=		${PYPKGPREFIX}-readline-[0-9]*
BUILDLINK_ABI_DEPENDS.pyreadline?=	${PYPKGPREFIX}-readline>=0nb2
BUILDLINK_PKGSRCDIR.pyreadline?=	../../devel/py-readline

.endif	# PYREADLINE_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
