# $NetBSD: Makefile,v 1.1 2025/08/15 05:49:28 kim Exp $

DISTNAME=	pipx-1.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pipx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pipx.pypa.io/
COMMENT=	Install and Run Python Applications in Isolated Environments
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pipx pipx${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
