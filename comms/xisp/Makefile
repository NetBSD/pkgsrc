# $NetBSD: Makefile,v 1.19 2004/04/25 01:09:38 wiz Exp $
#

DISTNAME=		xisp-2.6p1
PKGREVISION=		3
CATEGORIES=		comms x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/network/serial/} \
			http://xisp.hellug.gr/release/ \
			ftp://argeas.cs-net.gr/pub/unix/linux/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xisp.hellug.gr/
COMMENT=		User-friendly X11 interface to pppd/chat

USE_BUILDLINK3=		YES
USE_X11BASE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xisp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xisp/
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/xisp/

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
