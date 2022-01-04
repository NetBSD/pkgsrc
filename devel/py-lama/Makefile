# $NetBSD: Makefile,v 1.8 2022/01/04 20:53:14 wiz Exp $

DISTNAME=	pylama-7.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylama/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/klen/pylama
COMMENT=	Code audit tool for Python
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.3.1:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-docstyle>=2.0.0:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-flakes>=1.5.0:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.5.2:../../devel/py-mccabe
# extensions
DEPENDS+=	${PYPKGPREFIX}-eradicate-[0-9]*:../../textproc/py-eradicate
DEPENDS+=	${PYPKGPREFIX}-radon>=1.4.2:../../devel/py-radon

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pylama pylama-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
