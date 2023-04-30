# $NetBSD: Makefile,v 1.6 2023/04/30 12:25:59 wiz Exp $

DISTNAME=	lazr.config-2.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazr.config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/lazr.config/
COMMENT=	Create configuration schemas, and process and validate configurations
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-lazr.delegates-[0-9]*:../../devel/py-lazr.delegates
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
