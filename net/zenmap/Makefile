# $NetBSD: Makefile,v 1.15 2024/11/11 07:28:52 wiz Exp $

.include "../../net/nmap/Makefile.common"

PKGNAME=	${DISTNAME:S/nmap/zenmap/}

COMMENT=	Nmap Security Scanner GUI

WRKSRC=		${WRKDIR}/${DISTNAME}/zenmap

EXTRACT_ELEMENTS=	${DISTNAME}/zenmap

WHEEL_NAME=	zenmap-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	gtk3+-[0-9]*:../../x11/gtk3
DEPENDS+=	nmap-[0-9]*:../../net/nmap
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
