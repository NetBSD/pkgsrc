# $NetBSD: Makefile,v 1.4 1999/04/15 20:39:40 tron Exp $
#

DISTNAME=		xisp-2.5p4
CATEGORIES=		comms x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/network/serial/} \
			http://users.hol.gr/~dbouras/release/

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
