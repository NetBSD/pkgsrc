# $NetBSD: buildlink3.mk,v 1.7 2023/11/29 11:02:40 jperkin Exp $

BUILDLINK_TREE+=	python27

.if !defined(PYTHON27_BUILDLINK3_MK)
PYTHON27_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python27+=	python27>=2.7
BUILDLINK_ABI_DEPENDS.python27+=	python27>=2.7.1nb2
BUILDLINK_PKGSRCDIR.python27?=		../../lang/python27

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python27?=	${BUILDLINK_DEPMETHOD.python}
.endif

.if !${BUILDLINK_DEPMETHOD.python27:U:Mbuild}
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.endif # PYTHON27_BUILDLINK3_MK

BUILDLINK_TREE+=	-python27
