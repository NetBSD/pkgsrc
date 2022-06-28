# $NetBSD: Makefile,v 1.22 2022/06/28 11:35:35 wiz Exp $

DISTNAME=		hackbot-2.21
PKGREVISION=		9
CATEGORIES=		security net
MASTER_SITES=		http://hackbot.stream-portal.org/
EXTRACT_SUFX=		.tgz

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://hackbot.stream-portal.org/
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
