# $NetBSD: Makefile,v 1.1 2022/01/11 19:12:31 adam Exp $

DISTNAME=	cleo-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cleo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sdispater/cleo
COMMENT=	Create beautiful and testable command-line interfaces
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-clikit>=0.6.0:../../comms/py-clikit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
