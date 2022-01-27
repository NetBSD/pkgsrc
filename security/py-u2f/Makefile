# $NetBSD: Makefile,v 1.6 2022/01/27 10:39:35 wiz Exp $

DISTNAME=	pyu2f-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyu2f/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/google/pyu2f
COMMENT=	U2F host library for interacting with a U2F device
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-fakefs>=2.4:../../devel/py-fakefs
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.0.1:../../devel/py-mock
# seems unused: https://github.com/google/pyu2f/issues/33
#TEST_DEPENDS+=	${PYPKGPREFIX}-unittest2>=0.5.1:../../devel/py-unittest2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
