# $NetBSD: Makefile,v 1.9 2024/09/13 08:36:28 wiz Exp $

DISTNAME=	kiwisolver-1.4.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kiwisolver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nucleic/kiwi
COMMENT=	Fast implementation of the Cassowary constraint solver
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	c c++

BUILDLINK_API_DEPENDS.py-cppy+=	${PYPKGPREFIX}-cppy>=1.2.1
.include "../../devel/py-cppy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
