# $NetBSD: Makefile,v 1.12 2012/01/27 08:23:06 obache Exp $
#

DISTNAME=		pyproj-1.8.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/pyproj/proj/}
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		http://pyproj.googlecode.com/files/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://code.google.com/p/pyproj/
COMMENT=		Python wrapper for proj
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	share/doc/${PKGNAME_NOREV}

post-install:
	${INSTALL} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}

.include "../../lang/python/distutils.mk"

.include "../../geography/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
