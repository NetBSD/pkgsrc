# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/07/25 16:04:09 drochner Exp $

.if !defined(PY_ZCONFIG_BUILDLINK2_MK)
PY_ZCONFIG_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pyzconfig
BUILDLINK_DEPENDS.pyzconfig?=		${PYPKGPREFIX}-zconfig-[0-9]*
BUILDLINK_PKGSRCDIR.pyzconfig?=		../../devel/py-zconfig

.endif	# PY_ZCONFIG_BUILDLINK2_MK
