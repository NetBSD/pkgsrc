# $NetBSD: Makefile,v 1.7 2023/03/29 09:34:10 wiz Exp $

DISTNAME=	cmake-language-server-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmake-language-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/regen100/cmake-language-server
COMMENT=	CMake Language Server Protocol Implementation
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pygls>=0.12:../../lang/py-pygls

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 308
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.8:../../devel/py-importlib-metadata
.endif

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cmake-language-server cmake-language-server-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
