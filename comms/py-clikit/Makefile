# $NetBSD: Makefile,v 1.1 2022/01/11 19:11:04 adam Exp $

DISTNAME=	clikit-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/clikit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sdispater/clikit
COMMENT=	Utilities to build beautiful and testable command line interfaces
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pastel>=0.2.0:../../comms/py-pastel
DEPENDS+=	${PYPKGPREFIX}-pylev>=1.3:../../textproc/py-pylev

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
