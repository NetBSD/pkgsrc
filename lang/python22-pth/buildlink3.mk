# $NetBSD: buildlink3.mk,v 1.2 2004/01/25 17:15:12 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PYTHON22_PTH_BUILDLINK3_MK:=	${PYTHON22_PTH_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	python22-pth
.endif

.if !empty(PYTHON22_PTH_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			python22-pth
BUILDLINK_DEPENDS.python22-pth+=	python22-pth>=2.2.3
BUILDLINK_PKGSRCDIR.python22-pth?=	../../lang/python22-pth

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python22-pth?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python22-pth+=	include/python2p2
BUILDLINK_LIBDIRS.python22-pth+=	lib/python2p2/config
BUILDLINK_TRANSFORM+=			l:python:python2p2

.endif # PYTHON22_PTH_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
