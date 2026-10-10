# $NetBSD: buildlink3.mk,v 1.1 2026/10/10 10:34:19 adam Exp $

BUILDLINK_TREE+=	python315

.if !defined(PYTHON315_BUILDLINK3_MK)
PYTHON315_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python315+=	python315>=3.15.0
BUILDLINK_PKGSRCDIR.python315?=		../../lang/python315

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python315?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python315+=	include/python3.15
BUILDLINK_LIBDIRS.python315+=	lib/python3.15/config
BUILDLINK_TRANSFORM+=		l:python:python3.15

.if !${BUILDLINK_DEPMETHOD.python315:U:Mbuild}
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.endif # PYTHON315_BUILDLINK3_MK

BUILDLINK_TREE+=	-python315
