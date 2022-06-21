# $NetBSD: Makefile,v 1.84 2022/06/21 22:10:43 joerg Exp $

DISTNAME=	reportlab-3.5.68
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reportlab/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYTHON_VERSIONED_DEPENDENCIES=	Pillow pyphen

PYSETUPARGS+=	--no-download-t1-files
PYSETUPARGS+=	--use-system-libart

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
