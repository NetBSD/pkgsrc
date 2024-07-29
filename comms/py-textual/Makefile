# $NetBSD: Makefile,v 1.2 2024/07/29 07:29:03 wiz Exp $

DISTNAME=	textual-0.74.0
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

USE_LANGUAGES=	# none

# as of 0.72.0
# 306 failed, 1177 passed, 1354 skipped, 3 xfailed, 1431 warnings, 8 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
