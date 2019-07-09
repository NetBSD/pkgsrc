# $NetBSD: Makefile,v 1.22 2019/07/09 11:35:14 nia Exp $

DISTNAME=	amqp-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/amqp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://amqp.readthedocs.io/
COMMENT=	Low-level AMQP client for Python
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-vine>=1.1.3:../../devel/py-vine
TEST_DEPENDS+=	${PYPKGPREFIX}-case>=1.3.1:../../devel/py-case
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar>=0.9.1:../../devel/py-test-sugar

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
