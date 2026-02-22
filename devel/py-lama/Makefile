# $NetBSD: Makefile,v 1.15 2026/02/22 11:51:38 wiz Exp $

DISTNAME=	pylama-8.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylama/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/klen/pylama
COMMENT=	Code audit tool for Python
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.7.0:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.9.1:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-docstyle>=6.1.1:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-flakes>=2.5.0:../../devel/py-flakes

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pylama pylama-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
