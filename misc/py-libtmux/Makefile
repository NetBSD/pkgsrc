# $NetBSD: Makefile,v 1.3 2026/06/24 17:53:57 gdt Exp $

DISTNAME=	libtmux-0.58.1
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
