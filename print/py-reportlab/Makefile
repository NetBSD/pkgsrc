# $NetBSD: Makefile,v 1.88 2023/01/29 21:17:37 ryoon Exp $

DISTNAME=	reportlab-3.6.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reportlab/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-pyphen-[0-9]*:../../textproc/py-pyphen

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUPARGS+=	--no-download-t1-files
PYSETUPARGS+=	--use-system-libart

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
