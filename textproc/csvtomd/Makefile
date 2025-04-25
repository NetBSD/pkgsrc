# $NetBSD: Makefile,v 1.16 2025/04/25 10:57:39 wiz Exp $

DISTNAME=	csvtomd-0.2.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mplewis/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/mplewis/csvtomd/
COMMENT=	Convert your CSV files into Markdown tables
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-pandocfilters-[0-9]*:../../textproc/py-pandocfilters
TOOL_DEPENDS+=	${PYPKGPREFIX}-sure-[0-9]*:../../devel/py-sure

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	csvtomd

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
