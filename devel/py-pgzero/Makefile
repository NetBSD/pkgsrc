# $NetBSD: Makefile,v 1.4 2026/06/28 15:41:17 wiz Exp $

DISTNAME=	pgzero-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel games python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pgzero/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pygame-zero.readthedocs.io/en/stable/index.html
COMMENT=	Zero-boilerplate 2D games framework
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pgzrun pgzrun-${PYVERSSUFFIX}

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
