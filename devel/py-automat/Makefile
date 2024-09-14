# $NetBSD: Makefile,v 1.11 2024/09/14 19:16:35 adam Exp $

DISTNAME=	automat-24.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=A/Automat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/glyph/Automat
COMMENT=	Self-service finite-state machines for the programmer on the go
LICENSE=	mit

WHEEL_NAME=	Automat-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=35.0.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
# visualize option needs both next dependencies
#DEPENDS+=	${PYPKGPREFIX}-graphviz>=0.5.2:../../graphics/py-graphviz
# but this one is a circular dependency
#DEPENDS+=	${PYPKGPREFIX}-twisted>=16.1.1:../../net/py-twisted

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} automat-visualize automat-visualize-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
