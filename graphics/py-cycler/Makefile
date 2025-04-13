# $NetBSD: Makefile,v 1.7 2025/04/13 11:10:30 wiz Exp $

DISTNAME=	cycler-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cycler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matplotlib/cycler
COMMENT=	Composable style cycles
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
