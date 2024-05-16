# $NetBSD: Makefile,v 1.13 2024/05/16 20:23:46 wiz Exp $

DISTNAME=	csvtomd-0.2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mplewis/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/mplewis/csvtomd/
COMMENT=	Convert your CSV files into Markdown tables
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-pandocfilters-[0-9]*:../../textproc/py-pandocfilters
TOOL_DEPENDS+=	${PYPKGPREFIX}-sure-[0-9]*:../../devel/py-sure
TOOL_DEPENDS+=	${PYPKGPREFIX}-pypandoc-[0-9]*:../../wip/py-pandoc

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	csvtomd

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
