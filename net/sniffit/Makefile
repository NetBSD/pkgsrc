# $NetBSD: Makefile,v 1.11 1999/07/25 00:36:31 hubertf Exp $
#

DISTNAME=		sniffit.0.3.5
PKGNAME=		sniffit-0.3.5
CATEGORIES=		net security
MASTER_SITES=		http://reptile.rug.ac.be/~coder/sniffit/files/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://reptile.rug.ac.be/~coder/sniffit/sniffit.html

NOT_FOR_PLATFORM=	*-*-alpha	# severe LP64 loss

DEPENDS=		ncurses-4.2:../../devel/ncurses
HAS_CONFIGURE=		YES
CONFIGURE_ENV+=		NCURSES_LOCATION=$(LOCALBASE)/include/ncurses.h
ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sniffit ${PREFIX}/sbin/sniffit
	${INSTALL_MAN}     ${WRKSRC}/sniffit.5 ${PREFIX}/man/man5
	${INSTALL_MAN}     ${WRKSRC}/sniffit.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
