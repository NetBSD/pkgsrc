# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:10:55 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PYTHON21_BUILDLINK3_MK:=	${PYTHON21_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	python21
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npython21}
BUILDLINK_PACKAGES+=	python21
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}python21

.if !empty(PYTHON21_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.python21+=	python21>=2.1
BUILDLINK_PKGSRCDIR.python21?=	../../lang/python21

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python21?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python21+=	include/python2.1
BUILDLINK_LIBDIRS.python21+=	lib/python2.1/config
BUILDLINK_TRANSFORM+=		l:python:python2.1

.endif	# PYTHON21_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
