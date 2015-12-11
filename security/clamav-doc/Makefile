# $NetBSD: Makefile,v 1.2 2015/12/11 16:31:06 adam Exp $

.include "../../security/clamav/Makefile.common"

PKGNAME=	${DISTNAME:S/clamav/clamav-doc/}
COMMENT=	Anti-virus toolkit documents

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

.include "../../mk/bsd.pkg.mk"
