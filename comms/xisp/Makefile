# $NetBSD: Makefile,v 1.30 2009/12/17 21:49:22 abs Exp $
#

DISTNAME=		xisp-2.7p4
CATEGORIES=		comms x11
MASTER_SITES=		http://xisp.hellug.gr/release/ \
			${MASTER_SITE_SUNSITE:=system/network/serial/} \
			ftp://argeas.cs-net.gr/pub/unix/linux/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xisp.hellug.gr/
COMMENT=		User-friendly X11 interface to pppd/chat

BUILD_DEFS+=		VARBASE
PKG_GROUPS=		${DIALER_GROUP}
PKG_GROUPS_VARS+=	DIALER_GROUP
MAKE_ENV+=		DIALER_GROUP="${DIALER_GROUP}"
MAKE_ENV+=		VARBASE=${VARBASE:Q}
MESSAGE_SUBST+=		DIALER_GROUP=${DIALER_GROUP}
# XXX TODO: maybe do MODEM_DEV also?

INSTALLATION_DIRS+=	share/doc/xisp
PKG_DESTDIR_SUPPORT=	destdir

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xisp/
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${DESTDIR}${PREFIX}/share/doc/xisp/

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
