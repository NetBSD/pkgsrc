# $NetBSD: Makefile,v 1.42 2023/10/21 17:09:53 gdt Exp $

DISTNAME=		xisp-2.7p4
PKGREVISION=		6
CATEGORIES=		comms x11
MASTER_SITES=		https://xisp.hellug.gr/release/
MASTER_SITES+=		${MASTER_SITE_SUNSITE:=system/network/serial/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xisp.hellug.gr/
COMMENT=		User-friendly X11 interface to pppd/chat

BUILD_DEFS+=		VARBASE
PKG_GROUPS=		${DIALER_GROUP}
PKG_GROUPS_VARS+=	DIALER_GROUP
MAKE_ENV+=		DIALER_GROUP="${DIALER_GROUP}"
MAKE_ENV+=		VARBASE=${VARBASE:Q}
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install:Q}
MESSAGE_SUBST+=		DIALER_GROUP=${DIALER_GROUP}
# XXX TODO: maybe do MODEM_DEV also?

INSTALLATION_DIRS+=	share/doc/xisp
PKG_DESTDIR_SUPPORT=	destdir
NOT_FOR_UNPRIVILEGED=	yes

CFLAGS.SunOS+=		-DSUNOS5x
LDFLAGS.SunOS+=		-lsocket -lnsl

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xisp/
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${DESTDIR}${PREFIX}/share/doc/xisp/

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
