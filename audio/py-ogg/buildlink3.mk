# $NetBSD: buildlink3.mk,v 1.17 2009/03/20 19:23:58 joerg Exp $

BUILDLINK_TREE+=	pyogg

.if !defined(PYOGG_BUILDLINK3_MK)
PYOGG_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyogg+=	${PYPKGPREFIX}-ogg>=1.3
BUILDLINK_ABI_DEPENDS.pyogg?=	${PYPKGPREFIX}-ogg>=1.3nb2
BUILDLINK_PKGSRCDIR.pyogg?=	../../audio/py-ogg

.include "../../multimedia/libogg/buildlink3.mk"
.endif # PYOGG_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyogg
