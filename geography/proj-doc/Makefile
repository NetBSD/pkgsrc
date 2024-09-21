# $NetBSD: Makefile,v 1.9 2024/09/21 23:29:58 gdt Exp $

# \todo Complete rototill because what is packaged here is no longer available.
# https://github.com/OSGeo/PROJ/archive/refs/tags/9.5.0.tar.gz
# docs subdir
# make latexpdf
# See doc/environment.yml for build requirements.

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
