# $NetBSD: Makefile,v 1.13 2002/04/17 04:45:08 fredb Exp $
#

DISTNAME=		xisp-2.6p1
PKGREVISION=		1
CATEGORIES=		comms x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/network/serial/} \
			http://xisp.hellug.gr/release/ \
			ftp://argeas.cs-net.gr/pub/unix/linux/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://xisp.hellug.gr/
COMMENT=		User-friendly X11 interface to pppd/chat

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		xforms>=0.9999:../../x11/xforms

USE_X11BASE=		YES
USE_XPM=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xisp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xisp/
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/xisp/

.include "../../mk/bsd.pkg.mk"
