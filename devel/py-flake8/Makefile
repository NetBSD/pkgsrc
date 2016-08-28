# $NetBSD: Makefile,v 1.3 2016/08/28 15:48:29 wiz Exp $

DISTNAME=	flake8-2.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/flake8/
COMMENT=	Modular source code checker for Python programs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flakes>=0.8.1:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-mccabe-[0-9]*:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-pep8-[0-9]*:../../devel/py-pep8

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/flake8 ${DESTDIR}${PREFIX}/bin/flake8-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
