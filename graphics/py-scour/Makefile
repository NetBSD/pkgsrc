# $NetBSD: Makefile,v 1.5 2025/04/22 20:20:14 wiz Exp $

DISTNAME=	scour-0.38.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scour/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scour-project/scour
COMMENT=	Scour SVG Optimizer
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/scour \
		${DESTDIR}${PREFIX}/bin/scour-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
