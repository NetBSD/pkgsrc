# $NetBSD: buildlink3.mk,v 1.2 2023/11/29 11:02:41 jperkin Exp $

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

.if !${BUILDLINK_DEPMETHOD.python38:U:Mbuild}
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.endif # PYTHON38_BUILDLINK3_MK

BUILDLINK_TREE+=	-python38
