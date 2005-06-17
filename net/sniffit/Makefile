# $NetBSD: Makefile,v 1.29 2005/06/17 03:50:28 jlam Exp $
#

DISTNAME=		sniffit.0.3.5
PKGNAME=		sniffit-0.3.5
PKGREVISION=		2
CATEGORIES=		net security
MASTER_SITES=		http://reptile.rug.ac.be/~coder/sniffit/files/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://reptile.rug.ac.be/~coder/sniffit/sniffit.html
COMMENT=		Packet sniffer program

NOT_FOR_PLATFORM=	*-*-alpha	# severe LP64 loss

GNU_CONFIGURE=		YES
BUILD_TARGET=
INSTALLATION_DIRS=	man/man5 man/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sniffit ${PREFIX}/sbin/sniffit
	${INSTALL_MAN}     ${WRKSRC}/sniffit.5 ${PREFIX}/man/man5
	${INSTALL_MAN}     ${WRKSRC}/sniffit.8 ${PREFIX}/man/man8

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
