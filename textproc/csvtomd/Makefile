# $NetBSD: Makefile,v 1.11 2024/05/16 17:06:24 cheusov Exp $

DISTNAME=	csvtomd-0.2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mplewis/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/mplewis/csvtomd/
COMMENT=	Convert your CSV files into Markdown tables
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pandocfilters-[0-9]*:../../textproc/py-pandocfilters
TOOL_DEPENDS+=	${PYPKGPREFIX}-sure-[0-9]*:../../devel/py-sure
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TOOL_DEPENDS+=	${PYPKGPREFIX}-pypandoc-[0-9]*:../../wip/py-pandoc

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	csvtomd

USE_PKG_RESOURCES=	yes

# PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUP=		setup.py

do-test:
	${RUN} cd ${WRKSRC} ; ${SETENV} ${TEST_ENV} py.test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
