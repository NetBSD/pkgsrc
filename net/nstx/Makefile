# $NetBSD: Makefile,v 1.8 2017/10/24 00:00:35 khorben Exp $
#

DISTNAME=		nstx-1.1-beta6
PKGREVISION=		1
PKGNAME=		${DISTNAME:S/-beta/beta/}
CATEGORIES=		net
#MASTER_SITES=		http://nstx.dereference.de/nstx/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://nstx.dereference.de/nstx/
COMMENT=		Nameserver Transfer Protocol

MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS+=	bin share/doc/nstx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nstxcd ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nstxd ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nstx

.include "../../mk/bsd.pkg.mk"
