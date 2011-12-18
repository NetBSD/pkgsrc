# $NetBSD: Makefile,v 1.28 2011/12/18 18:18:50 dholland Exp $

DISTNAME=	snooper-19991202
PKGREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.foretune.co.jp/pub/tools/snooper/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Serial line protocol analyzer (need two serial interfaces)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/snooper
GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	build
BUILD_DIRS=	build

INSTALLATION_DIRS+=	share/doc/snooper

PKG_GROUPS=		${DIALER_GROUP}
PKG_USERS=		${UUCP_USER}:${UUCP_GROUP}
PKG_GROUPS_VARS+=	DIALER_GROUP UUCP_GROUP
PKG_USERS_VARS=		UUCP_USER
SPECIAL_PERMS+=		${PREFIX}/bin/snooper ${UUCP_USER} ${DIALER_GROUP} 4555

post-extract:
	${RM} ${WRKSRC}/build/.depend

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/snooper

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
