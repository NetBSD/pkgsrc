# $NetBSD: Makefile,v 1.1 2026/04/01 12:53:30 adam Exp $

DISTNAME=	setuptools_gettext-0.1.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools-gettext/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/breezy-team/setuptools-gettext
COMMENT=	Setuptools gettext extension plugin
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.2.1:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
