# $NetBSD: Makefile,v 1.28 2007/07/04 20:54:34 jlam Exp $
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
PKG_GROUPS_VARS+=	DIALER_GROUP
MAKE_ENV+=		DIALER_GROUP="${DIALER_GROUP}"
MAKE_ENV+=		VARBASE=${VARBASE:Q}
MESSAGE_SUBST+=		DIALER_GROUP=${DIALER_GROUP}
# XXX TODO: maybe do MODEM_DEV also?

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xisp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xisp/
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/xisp/

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
