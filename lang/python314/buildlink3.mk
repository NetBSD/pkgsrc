# $NetBSD: buildlink3.mk,v 1.1 2025/10/08 07:13:08 adam Exp $

BUILDLINK_TREE+=	python314

.if !defined(PYTHON314_BUILDLINK3_MK)
PYTHON314_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python314+=	python314>=3.14.0
BUILDLINK_PKGSRCDIR.python314?=		../../lang/python314

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python314?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python314+=	include/python3.14
BUILDLINK_LIBDIRS.python314+=	lib/python3.14/config
BUILDLINK_TRANSFORM+=		l:python:python3.14

.if !${BUILDLINK_DEPMETHOD.python314:U:Mbuild}
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.endif # PYTHON314_BUILDLINK3_MK

BUILDLINK_TREE+=	-python314
