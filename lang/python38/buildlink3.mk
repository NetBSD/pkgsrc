# $NetBSD: buildlink3.mk,v 1.1 2019/10/15 16:51:19 adam Exp $

BUILDLINK_TREE+=	python38

.if !defined(PYTHON38_BUILDLINK3_MK)
PYTHON38_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python38+=	python38>=3.8.0
BUILDLINK_PKGSRCDIR.python38?=		../../lang/python38

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python38?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python38+=	include/python3.8
BUILDLINK_LIBDIRS.python38+=	lib/python3.8/config
BUILDLINK_TRANSFORM+=		l:python:python3.8

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON38_BUILDLINK3_MK

BUILDLINK_TREE+=	-python38
