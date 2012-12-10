# $NetBSD: buildlink3.mk,v 1.1 2012/12/10 03:15:48 tsarna Exp $

BUILDLINK_TREE+=	python33

.if !defined(PYTHON33_BUILDLINK3_MK)
PYTHON33_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python33+=	python33>=3.3
BUILDLINK_PKGSRCDIR.python33?=		../../lang/python33

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python33?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python33+=	include/python3.3
BUILDLINK_LIBDIRS.python33+=	lib/python3.3/config
BUILDLINK_TRANSFORM+=		l:python:python3.3

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON33_BUILDLINK3_MK

BUILDLINK_TREE+=	-python33
