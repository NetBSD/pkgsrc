# $NetBSD: Makefile,v 1.7 2022/05/15 04:46:32 wiz Exp $

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
