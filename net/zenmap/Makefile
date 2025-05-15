# $NetBSD: Makefile,v 1.19 2025/05/15 15:44:41 adam Exp $

.include "../../net/nmap/Makefile.common"

PKGNAME=	${DISTNAME:S/nmap/zenmap/}

COMMENT=	Nmap Security Scanner GUI

WRKSRC=		${WRKDIR}/${DISTNAME}/zenmap

EXTRACT_ELEMENTS=	${DISTNAME}/zenmap

WHEEL_NAME=	zenmap-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

DEPENDS+=	gtk3+-[0-9]*:../../x11/gtk3
DEPENDS+=	nmap-[0-9]*:../../net/nmap
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
