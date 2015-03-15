# $NetBSD: Makefile,v 1.1 2015/03/15 00:55:06 taca Exp $

DISTNAME=	clamav-${CLAMAV_VERSION}
PKGNAME=	clamav-doc-${CLAMAV_VERSION}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clamav/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clamav.net/
COMMENT=	Anti-virus toolkit documents
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_TOOLS+=	pax

DOCDIR=		${PREFIX}/share/doc/clamav
PDFDOC=		clamav-mirror-howto.pdf clamdoc.pdf phishsigs_howto.pdf \
		signatures.pdf

INSTALLATION_DIRS+=	${DOCDIR}/html

do-install:
	cd ${WRKSRC}/docs && for f in ${PDFDOC}; do \
		${INSTALL_DATA} $$f ${DESTDIR}${DOCDIR}; \
	done
	cd ${WRKSRC}/docs && ${FIND} html -type f -print | \
		pax -rw ${DESTDIR}${DOCDIR}

.include "../../security/clamav/Makefile.common"
.include "../../mk/bsd.pkg.mk"
