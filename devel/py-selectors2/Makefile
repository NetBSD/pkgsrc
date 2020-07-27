# $NetBSD: Makefile,v 1.2 2020/07/27 13:41:42 adam Exp $

DISTNAME=	selectors2-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/selectors2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sethmlarson/selectors2
COMMENT=	Back-ported, durable, and portable selectors
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=5.2.2:../../sysutils/py-psutil

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
