# $NetBSD: Makefile,v 1.4 2010/02/11 22:20:52 joerg Exp $
#

DISTNAME=		nstx-1.1-beta6
PKGNAME=		${DISTNAME:S/-beta/beta/}
CATEGORIES=		net
MASTER_SITES=		http://nstx.dereference.de/nstx/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://nstx.dereference.de/nstx/
COMMENT=		Nameserver Transfer Protocol

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	bin share/doc/nstx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nstxcd ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nstxd ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nstx

.include "../../mk/bsd.pkg.mk"
