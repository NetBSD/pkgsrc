# $NetBSD: Makefile,v 1.14 2016/07/21 13:16:24 wiz Exp $

DISTNAME=	dulwich-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dulwich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dulwich.io/
COMMENT=	Python implementation of Git
LICENSE=	gnu-gpl-v2

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
# also needs unpackaged simple and geventhttpclient

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
