# $NetBSD: Makefile,v 1.16.2.1 2002/07/01 17:45:03 jlam Exp $
#

DISTNAME=		sniffit.0.3.5
PKGNAME=		sniffit-0.3.5
CATEGORIES=		net security
MASTER_SITES=		http://reptile.rug.ac.be/~coder/sniffit/files/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://reptile.rug.ac.be/~coder/sniffit/sniffit.html
COMMENT=		Packet sniffer program

NOT_FOR_PLATFORM=	*-*-alpha	# severe LP64 loss

HAS_CONFIGURE=		YES
USE_BUILDLINK2=		YES
ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sniffit ${PREFIX}/sbin/sniffit
	${INSTALL_MAN}     ${WRKSRC}/sniffit.5 ${PREFIX}/man/man5
	${INSTALL_MAN}     ${WRKSRC}/sniffit.8 ${PREFIX}/man/man8

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
