# $NetBSD: buildlink3.mk,v 1.1 2004/01/25 14:15:33 recht Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PYTHON22_PTH_BUILDLINK3_MK:=	${PYTHON22_PTH_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	python22-pth
.endif

.if !empty(PYTHON22_PTH_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			python22-pth
BUILDLINK_DEPENDS.python22-pth?=		python22-pth>=2.2.3
BUILDLINK_PKGSRCDIR.python22-pth?=		../../lang/python22-pth

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python22pth?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_TRANSFORM+=		l:python:python2p2

BUILDLINK_CPPFLAGS.python22pth+= \
	-I${BUILDLINK_PREFIX.python22pth}/include/python2p2
BUILDLINK_LDFLAGS.python22pth+= \
	-L${BUILDLINK_PREFIX.python22pth}/lib/python2p2/config		\
	-Wl,-R${BUILDLINK_PREFIX.python22pth}/lib/python2p2/config

.endif # PYTHON22_PTH_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
