# $NetBSD: Makefile,v 1.3 1999/01/30 23:18:45 agc Exp $
#

DISTNAME=		xisp-2.5p4
CATEGORIES=		comms x11
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			http://users.hol.gr/~dbouras/release/
MASTER_SITE_SUBDIR=	system/network/serial

MAINTAINER=		lamj@stat.cmu.edu
HOMEPAGE=		http://users.hol.gr/~dbouras/

DEPENDS+=		xforms-0.88:../../x11/xforms

ONLY_FOR_ARCHS=		arm32 i386 m68k sparc ns32k

USE_X11BASE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xisp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xisp/
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/xisp/

.include "../../mk/bsd.pkg.mk"
