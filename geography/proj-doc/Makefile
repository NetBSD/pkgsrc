# $NetBSD: Makefile,v 1.11 2025/09/09 13:01:03 gdt Exp $

# https://proj.org/_/downloads/en/9.6/pdf/
VERSION=		9.6
DISTNAME=		proj-doc-${VERSION}
CATEGORIES=		geography
MASTER_SITES=		-https://proj.org/_/downloads/en/${VERSION}/pdf/
# Hack around assumption that it is an archive.
EXTRACT_SUFX=		.pdf

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://proj.org/
COMMENT=		PDF documentation for the PROJ cartographic projection software
LICENSE=		mit

# \todo Consider building the docs with sphinx and latex from the
# distribution tarball, and perhaps installing HTML too.  OTOH I am
# not sure if anyone really uses this package, and the current
# situation is good enough for operating offline.
NO_BUILD=		yes
INSTALLATION_DIRS+=	share/doc/proj

# Hack around extract thinking it must be an archive.
EXTRACT_CMD=		${CP} $$extract_file .

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} ${DESTDIR}${PREFIX}/share/doc/proj/

.include "../../mk/bsd.pkg.mk"
