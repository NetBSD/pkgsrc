# $NetBSD: Makefile,v 1.2 2004/01/20 12:25:33 agc Exp $

DISTNAME=		hackbot-2.15
CATEGORIES=		security net
MASTER_SITES=		http://ws.obit.nl/hackbot/ \
			http://www.xs4all.nl/~mvberkum/hackbot/ \
			http://webs.uolsinectis.com.ar/gbarosio/hackbot/
EXTRACT_SUFX=		.tgz

MAINTAINER=		nk@atki.net
HOMEPAGE=		http://ws.obit.nl/hackbot/
COMMENT=		Vulnerability scanner written in Perl

WRKSRC=			${WRKDIR}/hackbot
MANCOMPRESSED=		YES
USE_PERL5=		YES
REPLACE_PERL=		hackbot.pl

do-build:
	${SED} "s,/usr/local/etc,${PREFIX}/share/hackbot,g" ${WRKSRC}/hackbot.pl > ${WRKSRC}/hackbot.pl.done
	${MV} ${WRKSRC}/hackbot.pl.done ${WRKSRC}/hackbot.pl

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/hackbot
	${INSTALL_SCRIPT} ${WRKSRC}/hackbot.pl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cgi.db ${WRKSRC}/fingerprint.db ${PREFIX}/share/hackbot
	${INSTALL_MAN} ${WRKSRC}/hackbot.1.gz ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
