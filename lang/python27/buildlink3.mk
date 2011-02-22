# $NetBSD: buildlink3.mk,v 1.2 2011/02/22 10:50:37 adam Exp $

BUILDLINK_TREE+=	python27

.if !defined(PYTHON27_BUILDLINK3_MK)
PYTHON27_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python27+=	python27>=2.7
BUILDLINK_PKGSRCDIR.python27?=		../../lang/python27

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python27?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python27+=	include/python2.7
BUILDLINK_LIBDIRS.python27+=	lib/python2.7/config
BUILDLINK_TRANSFORM+=		l:python:python2.7

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON27_BUILDLINK3_MK

BUILDLINK_TREE+=	-python27
