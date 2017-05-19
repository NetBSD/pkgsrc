# $NetBSD: Makefile,v 1.2 2017/05/19 14:56:40 joerg Exp $

DISTNAME=	requests-mock-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-mock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://requests-mock.readthedocs.org/
COMMENT=	Mock out responses from the requests package
LICENSE=	apache-2.0

USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
# TEST_DEPENDS
#BUILD_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
