# $NetBSD: buildlink3.mk,v 1.1 2015/12/05 17:12:13 adam Exp $

BUILDLINK_TREE+=	python35

.if !defined(PYTHON35_BUILDLINK3_MK)
PYTHON35_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python35+=	python35>=3.5
BUILDLINK_PKGSRCDIR.python35?=		../../lang/python35

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python35?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python35+=	include/python3.5
BUILDLINK_LIBDIRS.python35+=	lib/python3.5/config
BUILDLINK_TRANSFORM+=		l:python:python3.5

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON35_BUILDLINK3_MK

BUILDLINK_TREE+=	-python35
