# $NetBSD: buildlink3.mk,v 1.1 2022/10/31 09:52:13 adam Exp $

BUILDLINK_TREE+=	python311

.if !defined(PYTHON311_BUILDLINK3_MK)
PYTHON311_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python311+=	python311>=3.11.0
BUILDLINK_PKGSRCDIR.python311?=		../../lang/python311

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python311?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python311+=	include/python3.11
BUILDLINK_LIBDIRS.python311+=	lib/python3.11/config
BUILDLINK_TRANSFORM+=		l:python:python3.11

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON311_BUILDLINK3_MK

BUILDLINK_TREE+=	-python311
