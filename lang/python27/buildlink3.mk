# $NetBSD: buildlink3.mk,v 1.6 2016/12/30 10:53:21 adam Exp $

BUILDLINK_TREE+=	python27

.if !defined(PYTHON27_BUILDLINK3_MK)
PYTHON27_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python27+=	python27>=2.7
BUILDLINK_ABI_DEPENDS.python27+=	python27>=2.7.1nb2
BUILDLINK_PKGSRCDIR.python27?=		../../lang/python27

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python27?=	${BUILDLINK_DEPMETHOD.python}
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON27_BUILDLINK3_MK

BUILDLINK_TREE+=	-python27
