# $NetBSD: buildlink3.mk,v 1.2 2023/11/29 11:02:41 jperkin Exp $

BUILDLINK_TREE+=	python39

.if !defined(PYTHON39_BUILDLINK3_MK)
PYTHON39_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python39+=	python39>=3.9.0
BUILDLINK_PKGSRCDIR.python39?=		../../lang/python39

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python39?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python39+=	include/python3.9
BUILDLINK_LIBDIRS.python39+=	lib/python3.9/config
BUILDLINK_TRANSFORM+=		l:python:python3.9

.if !${BUILDLINK_DEPMETHOD.python39:U:Mbuild}
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.endif # PYTHON39_BUILDLINK3_MK

BUILDLINK_TREE+=	-python39
