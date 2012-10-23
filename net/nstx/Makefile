# $NetBSD: Makefile,v 1.6 2012/10/23 17:18:43 asau Exp $
#

DISTNAME=		nstx-1.1-beta6
PKGNAME=		${DISTNAME:S/-beta/beta/}
CATEGORIES=		net
MASTER_SITES=		http://nstx.dereference.de/nstx/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://nstx.dereference.de/nstx/
COMMENT=		Nameserver Transfer Protocol

INSTALLATION_DIRS+=	bin share/doc/nstx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nstxcd ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nstxd ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nstx

.include "../../mk/bsd.pkg.mk"
