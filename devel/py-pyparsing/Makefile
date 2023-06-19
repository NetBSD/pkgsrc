# $NetBSD: Makefile,v 1.29 2023/06/19 08:02:42 adam Exp $

# Important: re-generate files/setup.py before updating.
DISTNAME=	pyparsing-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyparsing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyparsing/pyparsing
COMMENT=	Parsing module for Python
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Important: do not use wheel.mk. It depends on py-build,
# which depends py-packaging, and that depends on this package.
pre-configure:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
