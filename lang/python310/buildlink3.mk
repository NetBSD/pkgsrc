# $NetBSD: buildlink3.mk,v 1.2 2023/11/29 11:02:41 jperkin Exp $

BUILDLINK_TREE+=	python310

.if !defined(PYTHON310_BUILDLINK3_MK)
PYTHON310_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python310+=	python310>=3.10.0
BUILDLINK_PKGSRCDIR.python310?=		../../lang/python310

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python310?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python310+=	include/python3.10
BUILDLINK_LIBDIRS.python310+=	lib/python3.10/config
BUILDLINK_TRANSFORM+=		l:python:python3.10

.if !${BUILDLINK_DEPMETHOD.python310:U:Mbuild}
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.endif # PYTHON310_BUILDLINK3_MK

BUILDLINK_TREE+=	-python310
