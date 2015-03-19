# $NetBSD: Makefile,v 1.16 2015/03/19 16:16:58 gdt Exp $

VERSION=		1.9.4
PKGNAMEBASE=		pyproj
DISTNAME=		v${VERSION}rel
DIST_SUBDIR=		pyproj
EGG_NAME=		${PKGNAMEBASE}-${VERSION}
PKGNAME=		${PYPKGPREFIX}-${PKGNAMEBASE:S/pyproj/proj/}-${VERSION}
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_GITHUB:=jswhit/pyproj/archive/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://jswhit.github.io/pyproj/
#			https://github.com/jswhit/pyproj
COMMENT=		Python wrapper for proj
LICENSE=		mit

WRKSRC=			${WRKDIR}/${PKGNAMEBASE}-${VERSION}rel

INSTALLATION_DIRS=	share/doc/${PKGNAME_NOREV}

post-install:
	${INSTALL} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}

.include "../../lang/python/distutils.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
