# $NetBSD: Makefile,v 1.3 2023/08/03 08:00:23 adam Exp $

DISTNAME=	debugpy-1.6.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/debugpy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/debugpy
COMMENT=	Implementation of the Debug Adapter Protocol for Python
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 755 {} +
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} 644 {} +

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
