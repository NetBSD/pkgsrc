# $NetBSD: Makefile,v 1.3 2020/08/17 20:59:31 riastradh Exp $

DISTNAME=	pyu2f-0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyu2f/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/google/pyu2f
COMMENT=	U2F host library for interacting with a U2F device
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.0.1:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-fakefs-[0-9]*:../../devel/py-fakefs
TEST_DEPENDS+=	${PYPKGPREFIX}-unittest2>=0.5.1:../../devel/py-unittest2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
