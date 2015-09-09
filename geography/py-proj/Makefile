# $NetBSD: Makefile,v 1.17 2015/09/09 23:40:08 gdt Exp $

VERSION=		1.9.4
PKGNAMEBASE=		pyproj
DISTNAME=		v${VERSION}rel
DIST_SUBDIR=		pyproj
EGG_NAME=		${PKGNAMEBASE}-${VERSION}
PKGNAME=		${PYPKGPREFIX}-${PKGNAMEBASE:S/pyproj/proj/}-${VERSION}
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_GITHUB:=jswhit/pyproj/archive/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://jswhit.github.io/pyproj/
COMMENT=		Python wrapper for proj
LICENSE=		mit

WRKSRC=			${WRKDIR}/${PKGNAMEBASE}-${VERSION}rel

INSTALLATION_DIRS=	share/doc/${PKGNAME_NOREV}

# Horrible kludge: the package has a private copy of projects.h, which
# proj used to not install, and the private copy has RCSID-type macros
# which are needed.  Until this is fixed upstream, avoid the
# proj-provided projects.h.
pre-build:
	rm ${WRKDIR}/.buildlink/include/projects.h

post-install:
	${INSTALL} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}

.include "../../lang/python/distutils.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
