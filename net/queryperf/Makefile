# $NetBSD: Makefile,v 1.1 2006/08/09 18:20:46 tv Exp $
#

DISTNAME=		queryperf-nominum-2.1
PKGNAME=		${DISTNAME:S/-nominum-/-/}
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.nominum.com/pub/nominum/

MAINTAINER=		tv@NetBSD.org
HOMEPAGE=		ftp://ftp.nominum.com/pub/nominum/
COMMENT=		DNS performance and load tester

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		queryperf
USE_PKGINSTALL=		yes

EGDIR=			share/examples/queryperf
INSTALLATION_DIRS+=	bin
OWN_DIRS+=		share/doc/queryperf
OWN_DIRS+=		${EGDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/queryperf ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/queryperf/
	${INSTALL_SCRIPT} ${WRKSRC}/utils/gen-data-queryperf.py ${PREFIX}/${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/input/sample.* ${PREFIX}/${EGDIR}/

.include "../../mk/bsd.pkg.mk"
