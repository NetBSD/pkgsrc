# $NetBSD: Makefile,v 1.8 2025/04/24 07:06:40 wiz Exp $

DISTNAME=	rstr-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rstr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leapfrogonline/rstr
COMMENT=	Generate random strings in Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.3:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
