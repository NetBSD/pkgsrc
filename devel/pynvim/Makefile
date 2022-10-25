# $NetBSD: Makefile,v 1.1 2022/10/25 20:26:02 nikita Exp $

DISTNAME=	pynvim-0.4.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}
GITHUB_PROJECT=	pynvim
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neovim/pynvim/
COMMENT=	Python client for Neovim
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-greenlet>=1.1.3:../../devel/py-greenlet

# it does support python 2.7 and 3.4 or later
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
