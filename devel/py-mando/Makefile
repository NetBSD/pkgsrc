# $NetBSD: Makefile,v 1.6 2023/03/29 09:34:08 wiz Exp $

DISTNAME=	mando-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mando/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://mando.readthedocs.io/
COMMENT=	Create Python CLI apps with little to no effort at all
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} == 207
DEPENDS+=	${PYPKGPREFIX}-funcsigs-[0-9]*:../../devel/py-funcsigs
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
