# $NetBSD: Makefile,v 1.2 2026/05/09 13:49:39 wiz Exp $

DISTNAME=	libtmux-0.55.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tmux-python/}
GITHUB_PROJECT=	libtmux
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libtmux.git-pull.com/
COMMENT=	Typed Python API for tmux
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
