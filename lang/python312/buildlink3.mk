# $NetBSD: buildlink3.mk,v 1.1 2023/10/02 20:07:14 adam Exp $

BUILDLINK_TREE+=	python312

.if !defined(PYTHON312_BUILDLINK3_MK)
PYTHON312_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python312+=	python312>=3.12.0
BUILDLINK_PKGSRCDIR.python312?=		../../lang/python312

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python312?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python312+=	include/python3.12
BUILDLINK_LIBDIRS.python312+=	lib/python3.12/config
BUILDLINK_TRANSFORM+=		l:python:python3.12

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON312_BUILDLINK3_MK

BUILDLINK_TREE+=	-python312
