# $NetBSD: Makefile,v 1.14 2026/07/18 14:48:22 gdt Exp $

# URLs look like
#   https://proj.org/_/downloads/en/9.6/pdf/
# but upstream download contents are unstable.  A URL x.y may have
# x.y.z instead, and the x.y.z pdf may be replaced by a different
# x.y.z pdf (e.g. 9.8.1).  Posted on upstream email list 20260706.
#
# Beyond that, the upstream pdf seems to change randomly.  Not yet
# posted upstream because they have not responded to the previous
# instability complaint.
#
# VERSION is set to the proj version, and adds a .n nano version if we
# update to a new distfile.  DOWNLOAD_VERSION is major.minor only,
# because that's how RTD works.
VERSION=		9.8.1
DOWNLOAD_VERSION=	9.8
DISTNAME=		proj-doc-${VERSION}
CATEGORIES=		geography
# Used for updates, and then `make upload-distfiles`:
#MASTER_SITES=		-https://proj.org/_/downloads/en/${DOWNLOAD_VERSION}/pdf/
MASTER_SITES=		${MASTER_SITES_LOCAL}
# Hack around assumption that distfile is an archive, part 1.
EXTRACT_SUFX=		.pdf

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://proj.org/
COMMENT=		PDF documentation for the PROJ cartographic projection software
LICENSE=		mit

# \todo Consider building the docs with sphinx and latex from the
# distribution tarball, and perhaps installing HTML too.
NO_BUILD=		yes
INSTALLATION_DIRS+=	share/doc/proj

# Hack around assumption that distfile is an archive, part 2.
EXTRACT_CMD=		${CP} $$extract_file .

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} ${DESTDIR}${PREFIX}/share/doc/proj/

.include "../../mk/bsd.pkg.mk"
