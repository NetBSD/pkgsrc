# $NetBSD: Makefile,v 1.14 2021/12/14 08:56:06 adam Exp $

DISTNAME=	pycparser-2.21
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycparser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eliben/pycparser
COMMENT=	C parser in Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
