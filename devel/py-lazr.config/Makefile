# $NetBSD: Makefile,v 1.3 2020/07/10 19:48:22 adam Exp $

DISTNAME=	lazr.config-2.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazr.config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/lazr.config/
COMMENT=	Create configuration schemas, and process and validate configurations
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-lazr.delegates-[0-9]*:../../devel/py-lazr.delegates

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
