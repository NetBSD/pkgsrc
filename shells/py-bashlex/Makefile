# $NetBSD: Makefile,v 1.3 2025/04/13 08:11:47 adam Exp $

DISTNAME=	bashlex-0.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	shells python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bashlex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/idank/bashlex.git
COMMENT=	Python parser for bash
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
