# $NetBSD: Makefile,v 1.26 2006/10/06 22:14:44 reed Exp $
#

DISTNAME=		xisp-2.7p1
PKGREVISION=		3
CATEGORIES=		comms x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/network/serial/} \
			http://xisp.hellug.gr/release/ \
			ftp://argeas.cs-net.gr/pub/unix/linux/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xisp.hellug.gr/
COMMENT=		User-friendly X11 interface to pppd/chat

PKG_GROUPS=		${DIALER_GROUP}
BUILD_DEFS+=		DIALER_GROUP
MAKE_ENV+=		DIALER_GROUP="${DIALER_GROUP}"
MAKE_ENV+=		VARBASE=${VARBASE:Q}
MESSAGE_SUBST+=		DIALER_GROUP=${DIALER_GROUP}
# XXX TODO: maybe do MODEM_DEV also?

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xisp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xisp/
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/xisp/

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
