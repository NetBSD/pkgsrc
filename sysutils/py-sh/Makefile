# $NetBSD: Makefile,v 1.8 2022/08/24 09:25:56 wiz Exp $

DISTNAME=	sh-1.14.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/amoffat/sh
COMMENT=	Python subprocess replacement
LICENSE=	mit

# some test failures, see https://github.com/amoffat/sh/issues/347
PYTHON_VERSIONED_DEPENDENCIES+=	coverage:test

USE_LANGUAGES=	# none

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
