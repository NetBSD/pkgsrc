# $NetBSD: Makefile,v 1.4 2012/10/23 17:19:04 asau Exp $
#

DISTNAME=		queryperf-nominum-2.1
PKGNAME=		${DISTNAME:S/-nominum-/-/}
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.nominum.com/pub/nominum/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.nominum.com/pub/nominum/
COMMENT=		DNS performance and load tester

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		queryperf
USE_PKGINSTALL=		yes

EGDIR=			share/examples/queryperf
INSTALLATION_DIRS+=	bin share/doc/queryperf ${EGDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/queryperf ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/queryperf/
	${INSTALL_SCRIPT} ${WRKSRC}/utils/gen-data-queryperf.py ${DESTDIR}${PREFIX}/${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/input/sample.* ${DESTDIR}${PREFIX}/${EGDIR}/

.include "../../mk/bsd.pkg.mk"
