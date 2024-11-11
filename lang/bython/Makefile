# $NetBSD: Makefile,v 1.3 2024/11/11 07:28:36 wiz Exp $

VERSION=	0.8
DISTNAME=	bython-${VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=mathialo/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mathialo/bython/
COMMENT=	Python with braces. Because Python is awesome, but whitespace is awful
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

USE_TOOLS+=	bash
REPLACE_BASH+=	scripts/by2py
USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
