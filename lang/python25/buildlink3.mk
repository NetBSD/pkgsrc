# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/04/24 01:50:58 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PYTHON25_BUILDLINK3_MK:=	${PYTHON25_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	python25
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npython25}
BUILDLINK_PACKAGES+=	python25
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}python25

.if !empty(PYTHON25_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.python25+=	python25>=2.5
BUILDLINK_ABI_DEPENDS.python25+=	python25>=2.5.2
BUILDLINK_PKGSRCDIR.python25?=		../../lang/python25

.  if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python25?=	${BUILDLINK_DEPMETHOD.python}
.  endif

BUILDLINK_INCDIRS.python25+=	include/python2.5
BUILDLINK_LIBDIRS.python25+=	lib/python2.5/config
BUILDLINK_TRANSFORM+=		l:python:python2.5

.endif	# PYTHON25_BUILDLINK3_MK

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
