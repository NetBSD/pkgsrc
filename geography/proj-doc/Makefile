# $NetBSD: Makefile,v 1.7 2022/11/26 14:00:46 gdt Exp $

DISTNAME=		proj-gh-pages
PKGNAME=		proj-doc-9.1.0
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_GITHUB:=OSGeo/}
GITHUB_PROJECT=		proj
# Perhaps associated with 9.1.1, really.
GITHUB_TAG=		c8132e949948c532e9aef6722ae6eb3e74cbc519

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://proj.org/
COMMENT=		PDF documentation for the PROJ cartographic projection software
LICENSE=		mit

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/PROJ-${GITHUB_TAG}
INSTALLATION_DIRS+=	share/doc/proj
PREV_PKGPATH=		misc/proj-doc

do-install:
	${INSTALL_DATA} ${WRKSRC}/proj.pdf ${DESTDIR}${PREFIX}/share/doc/proj/

.include "../../mk/bsd.pkg.mk"
