# $NetBSD: Makefile,v 1.10 2024/10/19 05:52:53 adam Exp $

DISTNAME=	findpython-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/findpython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/frostming/findpython
COMMENT=	Utility to find Python versions on your system
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-packaging>=20:../../devel/py-packaging

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} findpython findpython-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
