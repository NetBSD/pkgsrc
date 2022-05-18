# $NetBSD: Makefile,v 1.28 2022/05/18 08:50:41 wiz Exp $

DISTNAME=	pyparsing-3.0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyparsing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyparsing/pyparsing
COMMENT=	Parsing module for Python
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# bug in 3.0.9
EGG_NAME=	pyparsing-3.0.8

# Important: do not use wheel.mk. It depends on py-build,
# which depends py-packaging, and that depends on this package.
pre-configure:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
