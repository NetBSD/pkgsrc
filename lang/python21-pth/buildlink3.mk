# $NetBSD: buildlink3.mk,v 1.1 2004/01/25 14:23:39 recht Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PYTHON21_PTH_BUILDLINK3_MK:=	${PYTHON21_PTH_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	python21-pth
.endif

.if !empty(PYTHON21_PTH_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			python21-pth
BUILDLINK_DEPENDS.python21-pth?=		python21-pth>=2.1.3
BUILDLINK_PKGSRCDIR.python21-pth?=		../../lang/python21-pth

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python21pth?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_TRANSFORM+=		l:python:python2p1

BUILDLINK_CPPFLAGS.python21pth+= \
	-I${BUILDLINK_PREFIX.python21pth}/include/python2p1
BUILDLINK_LDFLAGS.python21pth+= \
	-L${BUILDLINK_PREFIX.python21pth}/lib/python2p1/config		\
	-Wl,-R${BUILDLINK_PREFIX.python21pth}/lib/python2p1/config

.endif # PYTHON21_PTH_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
