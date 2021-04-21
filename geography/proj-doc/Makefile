# $NetBSD: Makefile,v 1.6 2021/04/21 19:38:07 gdt Exp $

DISTNAME=		proj-gh-pages
PKGNAME=		proj-doc-8.0
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_GITHUB:=OSGeo/}
#MASTER_SITES=		https://github.com/OSGeo/PROJ/blob//
GITHUB_PROJECT=		proj
GITHUB_TAG=		1f33284734c33ec14286914673ec02fd40fe3982

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://proj.org/
COMMENT=		PDF documentation for the PROJ cartographic projection software
LICENSE=		mit

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/PROJ-1f33284734c33ec14286914673ec02fd40fe3982
INSTALLATION_DIRS+=	share/doc/proj
PREV_PKGPATH=		misc/proj-doc

do-install:
	${INSTALL_DATA} ${WRKSRC}/proj.pdf ${DESTDIR}${PREFIX}/share/doc/proj/

.include "../../mk/bsd.pkg.mk"
