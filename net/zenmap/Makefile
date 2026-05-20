# $NetBSD: Makefile,v 1.22 2026/05/20 14:31:07 abs Exp $

.include "../../net/nmap/Makefile.common"

PKGNAME=	${DISTNAME:S/nmap/zenmap/}
PKGREVISION=	1

COMMENT=	Nmap Security Scanner GUI

WRKSRC=		${WRKDIR}/${DISTNAME}/zenmap

EXTRACT_ELEMENTS=	${DISTNAME}/zenmap

WHEEL_NAME=	zenmap-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-gettext>=0:../../devel/py-setuptools-gettext

USE_LANGUAGES=	# none

DEPENDS+=	gtk3+-[0-9]*:../../x11/gtk3
DEPENDS+=	nmap-[0-9]*:../../net/nmap
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
