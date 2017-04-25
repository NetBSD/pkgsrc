# $NetBSD: Makefile,v 1.1 2017/04/25 19:59:59 fhajny Exp $
#

DISTNAME=	lazr.config-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazr.config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/lazr.config/
COMMENT=	Create configuration schemas, and process and validate configurations
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-lazr.delegates-[0-9]*:../../devel/py-lazr.delegates

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
