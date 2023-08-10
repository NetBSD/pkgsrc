# $NetBSD: Makefile,v 1.16 2023/08/10 14:10:40 gutteridge Exp $

DISTNAME=	ReText-8.0.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	editors python
MASTER_SITES=	${MASTER_SITE_PYPI:=R/ReText/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/retext-project/retext
COMMENT=	Simple but powerful editor for Markdown and reStructuredText
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-enchant-[0-9]*:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-markups-[0-9]*:../../textproc/py-markups
DEPENDS+=	${PYPKGPREFIX}-qt6-[0-9]*:../../x11/py-qt6
DEPENDS+=	${PYPKGPREFIX}-sip-qt6-[0-9]*:../../x11/py-sip-qt6

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 # py-markups

USE_PKG_RESOURCES=	yes

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
