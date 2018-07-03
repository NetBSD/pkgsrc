# $NetBSD: buildlink3.mk,v 1.1 2018/07/03 03:55:40 adam Exp $

BUILDLINK_TREE+=	python37

.if !defined(PYTHON37_BUILDLINK3_MK)
PYTHON37_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python37+=	python37>=3.7.0
BUILDLINK_PKGSRCDIR.python37?=		../../lang/python37

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python37?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python37+=	include/python3.7
BUILDLINK_LIBDIRS.python37+=	lib/python3.7/config
BUILDLINK_TRANSFORM+=		l:python:python3.7

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON37_BUILDLINK3_MK

BUILDLINK_TREE+=	-python37
