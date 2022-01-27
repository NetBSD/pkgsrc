# $NetBSD: Makefile,v 1.4 2022/01/27 11:39:38 wiz Exp $

DISTNAME=	case-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/case/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celery/case
COMMENT=	Python unittest utilities
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-mock>=2.0:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-six>=1.3.7:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=3.0:../../devel/py-coverage

USE_LANGUAGES=		# none

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py27"
DEPENDS+=	${PYPKGPREFIX}-unittest2>=0.5.1:../../devel/py-unittest2
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
