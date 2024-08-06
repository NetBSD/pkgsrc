# $NetBSD: Makefile,v 1.4 2024/08/06 13:12:00 wiz Exp $

DISTNAME=	textual-0.75.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/textual/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Textualize/textual
COMMENT=	Modern Text User Interface framework
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-rich>=13.3.3:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.4.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-markdown-it-py-[0-9]*:../../textproc/py-markdown-it-py
# optional
#DEPENDS+=	${PYPKGPREFIX}-tree-sitter>=0.20.1:../../wip/py-tree-sitter
TEST_DEPENDS+=	${PYPKGPREFIX}-test-textual-snapshot>=0.4.0:../../devel/py-test-textual-snapshot
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

# as of 0.75.1
# 321 failed, 1187 passed, 1369 skipped, 3 xfailed, 1446 warnings, 8 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
