# $NetBSD: buildlink3.mk,v 1.3 2006/04/12 10:27:21 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PYEXTCLASS_BUILDLINK3_MK:=	${PYEXTCLASS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyextclass
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyextclass}
BUILDLINK_PACKAGES+=	pyextclass

.if !empty(PYEXTCLASS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.pyextclass+=		py-extclass>=2.2.2nb1
BUILDLINK_ABI_DEPENDS.pyextclass+=	py-extclass>=2.2.2nb1
BUILDLINK_PKGSRCDIR.pyextclass?=	../../lang/py-extclass
.endif	# PYEXTCLASS_BUILDLINK3_MK

.include "../../lang/python20/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
