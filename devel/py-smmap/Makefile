# $NetBSD: Makefile,v 1.1 2020/09/10 14:59:20 taca Exp $

DISTNAME=	smmap-3.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=s/smmap/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/Byron/smmap
COMMENT=	Git implementation of a sliding window memory map manager
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-nosexcover-[0-9]*:../../devel/py-nosexcover
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=3.4:../../devel/py-coverage

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
