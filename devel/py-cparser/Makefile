# $NetBSD: Makefile,v 1.12 2018/09/24 11:20:24 adam Exp $

DISTNAME=	pycparser-2.19
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
