# $NetBSD: Makefile,v 1.3 2005/10/14 15:05:53 adrianp Exp $

DISTNAME=	Community-Rules-2.4
PKGNAME=	snort-rules-2.4
CATEGORIES=	net security
MASTER_SITES=	http://www.snort.org/pub-bin/downloads.cgi/Download/comm_rules/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.snort.org/
COMMENT=	Network Intrusion Detection System (Community Rules)

DEPENDS+=	snort{,-mysql,-pgsql}>=2.4.0:../../net/snort

NO_BUILD=	YES
NO_CONFIGURE=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/snort/rules
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snort/signatures

	${INSTALL_DATA} ${WRKDIR}/rules/*.rules ${PREFIX}/share/snort/rules
	${INSTALL_DATA} ${WRKDIR}/rules/*.map ${PREFIX}/share/snort/rules
	${INSTALL_DATA} ${WRKDIR}/docs/*.txt \
		${PREFIX}/share/doc/snort/signatures

.include "../../mk/bsd.pkg.mk"
