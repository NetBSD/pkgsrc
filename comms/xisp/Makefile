# $NetBSD: Makefile,v 1.11 2001/02/16 13:56:25 wiz Exp $
#

DISTNAME=		xisp-2.6p1
CATEGORIES=		comms x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/network/serial/} \
			http://hq.hellug.gr/~xisp/release/ \
			ftp://argeas.cs-net.gr/pub/unix/linux/ \
			http://users.hol.gr/~dbouras/release/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://users.hol.gr/~dbouras/
COMMENT=		User-friendly X11 interface to pppd/chat

DEPENDS+=		xforms>=0.88nb1:../../x11/xforms

USE_X11BASE=		YES
USE_XPM=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xisp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xisp/
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/xisp/

.include "../../mk/bsd.pkg.mk"
