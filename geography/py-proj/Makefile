# $NetBSD: Makefile,v 1.7 2008/04/25 20:39:09 joerg Exp $
#

DISTNAME=		pyproj-1.8.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/pyproj/proj/}
CATEGORIES=		geography
MASTER_SITES=		http://pyproj.googlecode.com/files/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://code.google.com/p/pyproj/
COMMENT=		Python wrapper for proj

PYDISTUTILSPKG=			true

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME}
	${INSTALL} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGNAME}

.include "../../lang/python/extension.mk"

.include "../../misc/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
