# $NetBSD: Makefile,v 1.3 2017/08/18 15:19:50 gdt Exp $

.include "../../security/clamav/Makefile.common"

PKGNAME=	${DISTNAME:S/clamav/clamav-doc/}
PKGREVISION=	3
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
