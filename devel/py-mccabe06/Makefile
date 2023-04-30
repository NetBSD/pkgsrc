# $NetBSD: Makefile,v 1.2 2023/04/30 18:42:52 wiz Exp $

DISTNAME=	mccabe-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mccabe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/mccabe/
COMMENT=	Mccabe plugin for the Python program checker flake8
LICENSE=	mit

#BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
