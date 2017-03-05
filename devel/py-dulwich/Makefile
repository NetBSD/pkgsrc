# $NetBSD: Makefile,v 1.18 2017/03/05 13:04:59 wiz Exp $

DISTNAME=	dulwich-0.17.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dulwich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dulwich.io/
COMMENT=	Python implementation of Git
LICENSE=	apache-2.0 OR gnu-gpl-v2

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
#BUILD_DEPENDS+=	${PYPKGPREFIX}-gevent-[0-9]*:../../net/py-gevent
# also needs unpackaged simple and geventhttpclient

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
