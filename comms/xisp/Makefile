# $NetBSD: Makefile,v 1.7 1999/06/20 21:06:17 tron Exp $
#

DISTNAME=		xisp-2.5p4
CATEGORIES=		comms x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/network/serial/} \
			http://users.hol.gr/~dbouras/release/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://users.hol.gr/~dbouras/

DEPENDS+=		xforms-0.88:../../x11/xforms
DEPENDS+=		xpm-3.4k:../../graphics/xpm

ONLY_FOR_PLATFORM=	NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k \
			NetBSD-*-sparc NetBSD-*-ns32k

USE_X11BASE=

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xisp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xisp/
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/xisp/

.include "../../mk/bsd.pkg.mk"
