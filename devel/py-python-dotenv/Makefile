# $NetBSD: Makefile,v 1.1 2018/05/03 02:26:55 wen Exp $

DISTNAME=	python-dotenv-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-dotenv/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://pypi.org/project/python-dotenv/
COMMENT=	Add .env support to your django/flask apps
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} dotenv dotenv-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
