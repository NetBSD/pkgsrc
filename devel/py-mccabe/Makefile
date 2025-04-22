# $NetBSD: Makefile,v 1.14 2025/04/22 20:04:58 wiz Exp $

DISTNAME=	mccabe-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mccabe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/mccabe/
COMMENT=	Mccabe plugin for the Python program checker flake8
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesmith-[0-9]*:../../devel/py-hypothesmith

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
