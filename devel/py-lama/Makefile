# $NetBSD: Makefile,v 1.13 2023/05/09 10:27:18 adam Exp $

DISTNAME=	pylama-8.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylama/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/klen/pylama
COMMENT=	Code audit tool for Python
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.7.0:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.9.1:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-docstyle>=6.1.1:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-flakes>=2.5.0:../../devel/py-flakes

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pylama pylama-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
