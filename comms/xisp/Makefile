# $NetBSD: Makefile,v 1.8 1999/08/26 19:01:44 jlam Exp $
#

DISTNAME=		xisp-2.6p1
CATEGORIES=		comms x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/network/serial/} \
			http://hq.hellug.gr/~xisp/release/ \
			ftp://argeas.cs-net.gr/pub/unix/linux/ \
			http://users.hol.gr/~dbouras/release/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://users.hol.gr/~dbouras/

DEPENDS+=		xforms-0.88:../../x11/xforms
DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xisp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xisp/
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/xisp/

.include "../../mk/bsd.pkg.mk"
