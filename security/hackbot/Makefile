# $NetBSD: Makefile,v 1.12 2013/05/31 12:41:51 wiz Exp $

DISTNAME=		hackbot-2.21
PKGREVISION=		1
CATEGORIES=		security net
MASTER_SITES=		http://www.xs4all.nl/~mvberkum/hackbot/
EXTRACT_SUFX=		.tgz

MAINTAINER=		nk@atki.net
HOMEPAGE=		http://ws.obit.nl/hackbot/
COMMENT=		Vulnerability scanner written in Perl

WRKSRC=			${WRKDIR}/hackbot
MANCOMPRESSED=		YES
USE_TOOLS+=		perl:run
REPLACE_PERL=		hackbot.pl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/hackbot

do-build:
	${SED} "s,/usr/local/etc,${PREFIX}/share/hackbot,g" ${WRKSRC}/hackbot.pl > ${WRKSRC}/hackbot.pl.done
	${MV} ${WRKSRC}/hackbot.pl.done ${WRKSRC}/hackbot.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hackbot.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cgi.db ${WRKSRC}/fingerprint.db \
	    ${DESTDIR}${PREFIX}/share/hackbot
	${INSTALL_MAN} ${WRKSRC}/hackbot.1.gz ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
