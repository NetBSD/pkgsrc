# $NetBSD: buildlink3.mk,v 1.4 2006/07/08 22:39:23 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PYEXTCLASS_BUILDLINK3_MK:=	${PYEXTCLASS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyextclass
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyextclass}
BUILDLINK_PACKAGES+=	pyextclass
BUILDLINK_ORDER+=	pyextclass

.if !empty(PYEXTCLASS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.pyextclass+=		py-extclass>=2.2.2nb1
BUILDLINK_ABI_DEPENDS.pyextclass+=	py-extclass>=2.2.2nb1
BUILDLINK_PKGSRCDIR.pyextclass?=	../../lang/py-extclass
.endif	# PYEXTCLASS_BUILDLINK3_MK

.include "../../lang/python20/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
