# $NetBSD: buildlink2.mk,v 1.2 2004/03/29 05:05:39 jlam Exp $

.if !defined(PY_ZCONFIG_BUILDLINK2_MK)
PY_ZCONFIG_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pyzconfig
BUILDLINK_PKGBASE.pyzconfig?=		${PYPKGPREFIX}-zconfig
BUILDLINK_DEPENDS.pyzconfig?=		${PYPKGPREFIX}-zconfig-[0-9]*
BUILDLINK_PKGSRCDIR.pyzconfig?=		../../devel/py-zconfig

.endif	# PY_ZCONFIG_BUILDLINK2_MK
