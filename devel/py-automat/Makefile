# $NetBSD: Makefile,v 1.14 2025/03/04 12:40:19 wiz Exp $

DISTNAME=	automat-24.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=A/Automat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/glyph/Automat
COMMENT=	Self-service finite-state machines for the programmer on the go
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
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
