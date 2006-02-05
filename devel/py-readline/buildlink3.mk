# $NetBSD: buildlink3.mk,v 1.2 2006/02/05 23:08:51 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PYREADLINE_BUILDLINK3_MK:=	${PYREADLINE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyreadline
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyreadline}
BUILDLINK_PACKAGES+=	pyreadline

.if !empty(PYREADLINE_BUILDLINK3_MK:M+)

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pyreadline+=		${PYPKGPREFIX}-readline-[0-9]*
BUILDLINK_RECOMMENDED.pyreadline?=	${PYPKGPREFIX}-readline>=0nb2
BUILDLINK_PKGSRCDIR.pyreadline?=	../../devel/py-readline

.endif	# PYREADLINE_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
