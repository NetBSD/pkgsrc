# $NetBSD: Makefile,v 1.3 2022/12/29 23:08:34 gutteridge Exp $

DISTNAME=	pynvim-0.4.3
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pynvim/neovim/}
CATEGORIES=	devel editors
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pynvim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neovim/pynvim
COMMENT=	Python client to Neovim
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-greenlet

DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.0:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-greenlet>=2.0.1:../../devel/py-greenlet
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
