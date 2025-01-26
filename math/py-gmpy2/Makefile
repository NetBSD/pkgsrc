# $NetBSD: Makefile,v 1.7 2025/01/26 16:13:20 he Exp $

DISTNAME=	gmpy2-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/a/alpha/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gmpy2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aleaxit/gmpy
COMMENT=	Interface to GMP/MPIR, MPFR, and MPC for Python
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-mpmath-[0-9]*:../../math/py-mpmath

.include "../../devel/gmp/buildlink3.mk"
BUILDLINK_API_DEPENDS.mpcomplex?=	mpcomplex>=1.2.1
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
