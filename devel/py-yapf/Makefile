# $NetBSD: Makefile,v 1.8 2023/04/23 00:04:35 gutteridge Exp $

DISTNAME=	yapf-0.33.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yapf/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/google/yapf
COMMENT=	Python files formatter
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0.1:../../textproc/py-tomli

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-tomli

USE_PKG_RESOURCES=	yes

post-install:
.for bin in yapf yapf-diff
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
