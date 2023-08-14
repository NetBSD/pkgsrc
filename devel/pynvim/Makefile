# $NetBSD: Makefile,v 1.3 2023/08/14 05:24:15 wiz Exp $

DISTNAME=	pynvim-0.4.3
PKGREVISION=	1
CATEGORIES=	devel editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}
GITHUB_PROJECT=	pynvim
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neovim/pynvim/
COMMENT=	Python client for Neovim
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-greenlet>=1.1.3:../../devel/py-greenlet
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-greenlet

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
