# $NetBSD: Makefile,v 1.4 2025/04/14 10:04:41 adam Exp $

VERSION=	0.8
DISTNAME=	bython-${VERSION}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=mathialo/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mathialo/bython/
COMMENT=	Python with braces. Because Python is awesome, but whitespace is awful
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_TOOLS+=	bash
REPLACE_BASH+=	scripts/by2py
USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
