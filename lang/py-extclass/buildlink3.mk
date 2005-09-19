# $NetBSD: buildlink3.mk,v 1.1 2005/09/19 14:56:26 hira Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PYEXTCLASS_BUILDLINK3_MK:=	${PYEXTCLASS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyextclass
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyextclass}
BUILDLINK_PACKAGES+=	pyextclass

.if !empty(PYEXTCLASS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pyextclass+=		py-extclass>=2.2.2nb1
BUILDLINK_RECOMMENDED.pyextclass+=	py-extclass>=2.2.2nb1
BUILDLINK_PKGSRCDIR.pyextclass?=	../../lang/py-extclass
.endif	# PYEXTCLASS_BUILDLINK3_MK

.include "../../lang/python20/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
