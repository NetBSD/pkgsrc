# $NetBSD: buildlink3.mk,v 1.2 2004/01/25 14:11:13 recht Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PYTHON23_PTH_BUILDLINK3_MK:=	${PYTHON23_PTH_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	python23-pth
.endif

.if !empty(PYTHON23_PTH_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			python23-pth
BUILDLINK_DEPENDS.python23-pth?=		python23-pth>=2.3.3
BUILDLINK_PKGSRCDIR.python23-pth?=		../../lang/python23-pth

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python23pth?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_TRANSFORM+=		l:python:python2p3

BUILDLINK_CPPFLAGS.python23pth+= \
	-I${BUILDLINK_PREFIX.python23pth}/include/python2p3
BUILDLINK_LDFLAGS.python23pth+= \
	-L${BUILDLINK_PREFIX.python23pth}/lib/python2p3/config		\
	-Wl,-R${BUILDLINK_PREFIX.python23pth}/lib/python2p3/config

.endif # PYTHON23_PTH_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
