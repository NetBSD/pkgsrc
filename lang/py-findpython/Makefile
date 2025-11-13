# $NetBSD: Makefile,v 1.13 2025/11/13 13:51:45 adam Exp $

DISTNAME=	findpython-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/findpython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/frostming/findpython
COMMENT=	Utility to find Python versions on your system
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-packaging>=20:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=4.3.6:../../misc/py-platformdirs

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} findpython findpython-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
