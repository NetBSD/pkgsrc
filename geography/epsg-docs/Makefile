# $NetBSD: Makefile,v 1.1.1.1 2007/07/28 11:09:48 gdt Exp $
#

DISTNAME=		G7-1
PKGNAME=		epsg-docs-${VERS}
VERS=			20070716
CATEGORIES=		geography databases
MASTER_SITES=		http://www.epsg.org/guides/docs/
DISTFILES=		G7-1.pdf G7-2.pdf
DIST_SUBDIR=		epsg-docs-${VERS}

MAINTAINER=		cngo@nmsu.edu
HOMEPAGE=		http://www.epsg.org/
COMMENT=		EPSG geodetic parameters database documentation

LICENSE=		epsg-license

# Docs were included in geography/epsg up to 6.11.2, but are released
# separately and hence now packaged separately.
CONFLICTS+=		epsg<6.13

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
DOCDIR=                 ${PREFIX}/share/doc/epsg

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/G7-1.pdf ${DOCDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/G7-2.pdf ${DOCDIR:Q}

.include "../../mk/bsd.pkg.mk"
