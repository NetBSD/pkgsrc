# $NetBSD: buildlink3.mk,v 1.15 2009/03/20 19:24:51 joerg Exp $

BUILDLINK_TREE+=	python23

.if !defined(PYTHON23_BUILDLINK3_MK)
PYTHON23_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python23+=	python23>=2.3
BUILDLINK_ABI_DEPENDS.python23?=	python23>=2.3.5nb6
BUILDLINK_PKGSRCDIR.python23?=	../../lang/python23

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python23?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python23+=	include/python2.3
BUILDLINK_LIBDIRS.python23+=	lib/python2.3/config
BUILDLINK_TRANSFORM+=		l:python:python2.3
.endif # PYTHON23_BUILDLINK3_MK

BUILDLINK_TREE+=	-python23

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "IRIX"
.  include "../../mk/bdb.buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
