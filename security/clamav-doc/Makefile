# $NetBSD: Makefile,v 1.6.4.1 2022/06/11 10:33:10 bsiegert Exp $

.include "../../security/clamav/Makefile.common"

PKGNAME=	${DISTNAME:S/clamav/clamav-doc/}
PKGREVISION=	1
COMMENT=	Anti-virus toolkit documents

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_TOOLS+=	pax

DOCDIR=		${PREFIX}/share/doc/clamav

INSTALLATION_DIRS+=	${DOCDIR}/html

pre-install:
	${CHMOD} -x ${WRKSRC}/docs/html/images/flamegraph.svg

do-install:
	cd ${WRKSRC}/docs && ${FIND} html -type f -print | \
		pax -rw ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
