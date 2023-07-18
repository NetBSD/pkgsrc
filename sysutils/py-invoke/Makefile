# $NetBSD: Makefile,v 1.3 2023/07/18 15:31:12 adam Exp $

DISTNAME=	invoke-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/invoke/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyinvoke.org/
COMMENT=	Pythonic task execution
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in inv invoke
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
