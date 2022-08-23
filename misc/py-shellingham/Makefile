# $NetBSD: Makefile,v 1.2 2022/08/23 10:38:36 adam Exp $

DISTNAME=	shellingham-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/shellingham/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sarugaku/shellingham
COMMENT=	Tool to detect surrounding shell
LICENSE=	isc

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
