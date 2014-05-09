# $NetBSD: buildlink3.mk,v 1.1 2014/05/09 02:27:14 wen Exp $

BUILDLINK_TREE+=	python34

.if !defined(PYTHON34_BUILDLINK3_MK)
PYTHON34_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python34+=	python34>=3.4
BUILDLINK_PKGSRCDIR.python34?=		../../lang/python34

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python34?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python34+=	include/python3.4
BUILDLINK_LIBDIRS.python34+=	lib/python3.4/config
BUILDLINK_TRANSFORM+=		l:python:python3.4

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON34_BUILDLINK3_MK

BUILDLINK_TREE+=	-python34
