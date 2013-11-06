# $NetBSD: buildlink3.mk,v 1.6 2013/11/06 07:25:49 adam Exp $

BUILDLINK_TREE+=	python26

.if !defined(PYTHON26_BUILDLINK3_MK)
PYTHON26_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python26+=	python26>=2.6
BUILDLINK_ABI_DEPENDS.python26+=		python26>=2.6.6nb8
BUILDLINK_PKGSRCDIR.python26?=		../../lang/python26

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python26?=	${BUILDLINK_DEPMETHOD.python}
.endif

#BUILDLINK_INCDIRS.python26+=	include/python2.6
#BUILDLINK_LIBDIRS.python26+=	lib/python2.6/config
#BUILDLINK_TRANSFORM+=		l:python:python2.6

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON26_BUILDLINK3_MK

BUILDLINK_TREE+=	-python26
