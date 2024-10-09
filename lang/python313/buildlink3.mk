# $NetBSD: buildlink3.mk,v 1.1 2024/10/09 19:53:19 adam Exp $

BUILDLINK_TREE+=	python313

.if !defined(PYTHON313_BUILDLINK3_MK)
PYTHON313_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python313+=	python313>=3.13.0
BUILDLINK_PKGSRCDIR.python313?=		../../lang/python313

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python313?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python313+=	include/python3.13
BUILDLINK_LIBDIRS.python313+=	lib/python3.13/config
BUILDLINK_TRANSFORM+=		l:python:python3.13

.if !${BUILDLINK_DEPMETHOD.python313:U:Mbuild}
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif

.endif # PYTHON313_BUILDLINK3_MK

BUILDLINK_TREE+=	-python313
