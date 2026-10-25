# $NetBSD: Makefile,v 1.9 2026/10/25 13:18:22 ktnb Exp $

DISTNAME=	brotlicffi-1.2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/brotlicffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/brotlicffi
COMMENT=	Python CFFI bindings to the Brotli library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi

MAKE_ENV+=	USE_SHARED_BROTLI=1

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		darwin not_darwin

.include "../../lang/python/pyversion.mk"

.if ${OPSYS} == "Darwin" && ${PYTHON_VERSION} > 314
PLIST.darwin=		yes
.else
PLIST.not_darwin=	yes
.endif

# tests need libbrotli sources in ${WRKSRC}/libbrotli

.include "../../archivers/brotli/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
