# $NetBSD: Makefile,v 1.10 2022/01/31 11:55:26 wiz Exp $

DISTNAME=	pylama-7.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylama/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/klen/pylama
COMMENT=	Code audit tool for Python
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.3.1:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-docstyle>=2.0.0:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-flakes>=1.5.0:../../devel/py-flakes
# extensions
DEPENDS+=	${PYPKGPREFIX}-eradicate-[0-9]*:../../textproc/py-eradicate
DEPENDS+=	${PYPKGPREFIX}-radon>=1.4.2:../../devel/py-radon

PYTHON_VERSIONED_DEPENDENCIES+=	mccabe
PYTHON_VERSIONED_DEPENDENCIES+=	test:test

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pylama pylama-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
