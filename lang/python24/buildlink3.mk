# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:56 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PYTHON24_BUILDLINK3_MK:=	${PYTHON24_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	python24
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npython24}
BUILDLINK_PACKAGES+=	python24
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}python24

.if !empty(PYTHON24_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.python24+=	python24>=2.4
BUILDLINK_ABI_DEPENDS.python24?=	python24>=2.4.2nb4
BUILDLINK_PKGSRCDIR.python24?=	../../lang/python24

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python24?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python24+=	include/python2.4
BUILDLINK_LIBDIRS.python24+=	lib/python2.4/config
BUILDLINK_TRANSFORM+=		l:python:python2.4

.endif	# PYTHON24_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
