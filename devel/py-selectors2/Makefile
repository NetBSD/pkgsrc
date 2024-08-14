# $NetBSD: Makefile,v 1.5 2024/08/14 12:57:04 wiz Exp $

DISTNAME=	selectors2-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/selectors2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sethmlarson/selectors2
COMMENT=	Back-ported, durable, and portable selectors
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_27_ACCEPTED=	yes

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} > 300
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
# only supports Python 3
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=5.2.2:../../sysutils/py-psutil
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
