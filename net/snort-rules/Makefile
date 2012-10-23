# $NetBSD: Makefile,v 1.6 2012/10/23 17:19:09 asau Exp $

DISTNAME=	Community-Rules-2.4
PKGNAME=	snort-rules-2.4
CATEGORIES=	net security
MASTER_SITES=	http://www.snort.org/pub-bin/downloads.cgi/Download/comm_rules/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.snort.org/
COMMENT=	Network Intrusion Detection System (Community Rules)

DEPENDS+=	snort{,-mysql,-pgsql}>=2.4.0:../../net/snort

NO_BUILD=	YES
NO_CONFIGURE=	YES

INSTALLATION_DIRS+=	share/snort/rules share/doc/snort/signatures

do-install:
	${INSTALL_DATA} ${WRKDIR}/rules/*.rules ${DESTDIR}${PREFIX}/share/snort/rules
	${INSTALL_DATA} ${WRKDIR}/rules/*.map ${DESTDIR}${PREFIX}/share/snort/rules
	${INSTALL_DATA} ${WRKDIR}/docs/*.txt \
		${DESTDIR}${PREFIX}/share/doc/snort/signatures

.include "../../mk/bsd.pkg.mk"
