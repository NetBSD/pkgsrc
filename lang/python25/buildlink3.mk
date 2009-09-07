# $NetBSD: buildlink3.mk,v 1.4 2009/09/07 18:44:08 drochner Exp $

BUILDLINK_TREE+=	python25

.if !defined(PYTHON25_BUILDLINK3_MK)
PYTHON25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python25+=	python25>=2.5
BUILDLINK_ABI_DEPENDS.python25+=	python25>=2.5.2
BUILDLINK_PKGSRCDIR.python25?=		../../lang/python25

.  if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python25?=	${BUILDLINK_DEPMETHOD.python}
.  endif

BUILDLINK_INCDIRS.python25+=	include/python2.5
BUILDLINK_LIBDIRS.python25+=	lib/python2.5/config
BUILDLINK_TRANSFORM+=		l:python:python2.5

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON25_BUILDLINK3_MK

BUILDLINK_TREE+=	-python25
