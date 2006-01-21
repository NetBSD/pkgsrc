# $NetBSD: Makefile,v 1.25 2006/01/21 18:57:41 jlam Exp $

DISTNAME=	gdmodule.c
PKGNAME=	${PYPKGPREFIX}-gd-1.3
PKGREVISION=	6
CATEGORIES=	graphics python
MASTER_SITES=	http://starship.python.net/~richard/gdmodule/
EXTRACT_SUFX=

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://starship.python.net/~richard/gdmodule/
COMMENT=	Python interface to gd graphics library

WRKSRC=		${WRKDIR}
BUILD_TARGET=	default

PYDISTUTILSPKG= yes
PYBINMODULE=    yes

post-patch:
	${SED} 's+@LOCALBASE@+${LOCALBASE}+g' ${FILESDIR}/Setup.in > ${WRKSRC}/setup.py

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
