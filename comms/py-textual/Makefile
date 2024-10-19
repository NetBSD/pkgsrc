# $NetBSD: Makefile,v 1.11 2024/10/19 11:34:15 wiz Exp $

DISTNAME=	textual-0.83.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/textual/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Textualize/textual
COMMENT=	Modern Text User Interface framework
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=4.2.2:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-rich>=13.3.3:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.4.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-markdown-it-py>=2.1.0:../../textproc/py-markdown-it-py
# optional, and also needs tree-sitter-languages, which is unpackaged because of
# https://github.com/grantjenks/py-tree-sitter-languages/issues/76
#DEPENDS+=	${PYPKGPREFIX}-tree-sitter>=0.20.1:../../textproc/py-tree-sitter
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-textual-snapshot>=1.0.0:../../devel/py-test-textual-snapshot
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-textual-dev>=1.2:../../comms/py-textual-dev

USE_LANGUAGES=	# none

# as of 0.83.0
# 32 failed, 2984 passed, 1 skipped, 4 xfailed, 2 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
