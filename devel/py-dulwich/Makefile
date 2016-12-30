# $NetBSD: Makefile,v 1.16 2016/12/30 00:55:33 wiz Exp $

DISTNAME=	dulwich-0.16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dulwich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dulwich.io/
COMMENT=	Python implementation of Git
LICENSE=	apache-2.0 OR gnu-gpl-v2

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
# also needs unpackaged simple and geventhttpclient

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
