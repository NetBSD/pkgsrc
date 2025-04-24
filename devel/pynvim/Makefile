# $NetBSD: Makefile,v 1.6 2025/04/24 07:57:43 wiz Exp $

DISTNAME=	pynvim-0.5.0
PKGREVISION=	1
CATEGORIES=	devel editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}
GITHUB_PROJECT=	pynvim
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neovim/pynvim/
COMMENT=	Python client for Neovim
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-greenlet>=1.1.3:../../devel/py-greenlet
TEST_DEPENDS+=	neovim-[0-9]*:../../editors/neovim

# as of 0.5.0
# 3 failed, 71 passed, 71 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
