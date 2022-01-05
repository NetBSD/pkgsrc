# $NetBSD: Makefile,v 1.11 2022/01/05 15:41:09 wiz Exp $

DISTNAME=	ReText-7.2.2
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	editors python
MASTER_SITES=	${MASTER_SITE_PYPI:=R/ReText/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/retext-project/retext
COMMENT=	Simple but powerful editor for Markdown and reStructuredText
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-enchant-[0-9]*:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-markups-[0-9]*:../../textproc/py-markups

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-markups

USE_PKG_RESOURCES=	yes

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
