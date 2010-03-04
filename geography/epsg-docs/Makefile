# $NetBSD: Makefile,v 1.4 2010/03/04 10:53:55 gdt Exp $
#

DISTNAME=		G7-1
PKGNAME=		epsg-docs-${VERS}
VERS=			200911
CATEGORIES=		geography databases
MASTER_SITES=		http://www.epsg.org/guides/docs/
DISTFILES=		G7-1.pdf G7-2.pdf
DIST_SUBDIR=		epsg-docs-${VERS}

MAINTAINER=		cngo@nmsu.edu
HOMEPAGE=		http://www.epsg.org/
COMMENT=		EPSG geodetic parameters database documentation
LICENSE=		epsg-license

PKG_DESTDIR_SUPPORT=	user-destdir

# Docs were included in geography/epsg up to 6.11.2, but are released
# separately and hence now packaged separately.
CONFLICTS+=		epsg<6.13

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
DOCDIR=                 ${PREFIX}/share/doc/epsg

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/G7-1.pdf ${DESTDIR}${DOCDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/G7-2.pdf ${DESTDIR}${DOCDIR:Q}

.include "../../mk/bsd.pkg.mk"
