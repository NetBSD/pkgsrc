# $NetBSD: Makefile,v 1.2 2017/10/20 15:57:52 minskim Exp $

DISTNAME=	autopep8-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autopep8/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/hhatto/autopep8
COMMENT=	Automatic formatter of Python code to conform to PEP 8
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.3:../../devel/py-codestyle

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} autopep8 autopep8-${PYVERSSUFFIX}

.include "../../mk/bsd.pkg.mk"
