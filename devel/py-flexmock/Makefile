# $NetBSD: Makefile,v 1.6 2019/06/10 14:48:05 adam Exp $

DISTNAME=	flexmock-0.10.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flexmock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bkabrda/flexmock
COMMENT=	Mock/Stub/Spy library for Python
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/tests && ${PYTHONBIN} -m unittest flexmock_test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
