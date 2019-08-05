# $NetBSD: Makefile,v 1.5 2019/08/05 14:47:33 prlw1 Exp $

.include "../../security/clamav/Makefile.common"

PKGNAME=	${DISTNAME:S/clamav/clamav-doc/}
COMMENT=	Anti-virus toolkit documents

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_TOOLS+=	pax

DOCDIR=		${PREFIX}/share/doc/clamav

INSTALLATION_DIRS+=	${DOCDIR}/html

do-install:
	cd ${WRKSRC}/docs && ${FIND} html -type f -print | \
		pax -rw ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
