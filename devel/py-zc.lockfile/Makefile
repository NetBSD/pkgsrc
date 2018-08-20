# $NetBSD: Makefile,v 1.1 2018/08/20 12:58:06 adam Exp $

DISTNAME=	zc.lockfile-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zc.lockfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zc.lockfile
COMMENT=	Basic inter-process locks
LICENSE=	zpl-2.1

TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing-[0-9]*:../../devel/py-zope.testing

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
