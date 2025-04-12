# $NetBSD: Makefile,v 1.3 2025/04/12 11:33:33 adam Exp $

DISTNAME=	lib3to6-202107.1047
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lib3to6/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mbarkhau/lib3to6
COMMENT=	Compile Python 3.6+ code to Python 2.7+
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pathlib2>=0:../../devel/py-pathlib2
DEPENDS+=	${PYPKGPREFIX}-astor>=0:../../devel/py-astor
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} lib3to6 lib3to6-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
