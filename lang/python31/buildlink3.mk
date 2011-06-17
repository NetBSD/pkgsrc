# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/06/17 00:10:19 reed Exp $

BUILDLINK_TREE+=	python31

.if !defined(PYTHON31_BUILDLINK3_MK)
PYTHON31_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python31+=	python31>=3.1
BUILDLINK_PKGSRCDIR.python31?=		../../lang/python31

.  if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python31?=	${BUILDLINK_DEPMETHOD.python}
.  endif

BUILDLINK_INCDIRS.python31+=	include/python3.1
BUILDLINK_LIBDIRS.python31+=	lib/python3.1/config
BUILDLINK_TRANSFORM+=		l:python:python3.1

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON31_BUILDLINK3_MK

BUILDLINK_TREE+=	-python31
