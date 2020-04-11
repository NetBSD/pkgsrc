# $NetBSD: Makefile,v 1.23 2020/04/11 14:02:50 adam Exp $

DISTNAME=	msgpack-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msgpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://msgpack.org/
COMMENT=	MessagePack (de)serializer for Python
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	c c++

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} test


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
