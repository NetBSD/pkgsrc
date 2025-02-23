# $NetBSD: Makefile,v 1.13 2025/02/23 18:55:53 wiz Exp $

DISTNAME=	pydyf-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydyf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.courtbouillon.org/pydyf
COMMENT=	Low-level PDF generator
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	ghostscript-agpl-[0-9]*:../../print/ghostscript-agpl
TEST_DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow

USE_LANGUAGES=	# none

post-extract:
	${CHMOD} -x ${WRKSRC}/pydyf/__init__.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
