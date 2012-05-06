# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/05/06 13:12:12 obache Exp $

BUILDLINK_TREE+=	python32

.if !defined(PYTHON32_BUILDLINK3_MK)
PYTHON32_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python32+=	python32>=3.2
BUILDLINK_PKGSRCDIR.python32?=		../../lang/python32

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python32?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python32+=	include/python3.2
BUILDLINK_LIBDIRS.python32+=	lib/python3.2/config
BUILDLINK_TRANSFORM+=		l:python:python3.2

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON32_BUILDLINK3_MK

BUILDLINK_TREE+=	-python32
