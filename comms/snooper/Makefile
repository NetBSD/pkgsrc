# $NetBSD: Makefile,v 1.27 2011/12/18 15:59:57 dholland Exp $

DISTNAME=	snooper-19991202
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.foretune.co.jp/pub/tools/snooper/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Serial line protocol analyzer (need two serial interfaces)

WRKSRC=		${WRKDIR}/snooper
GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	build
BUILD_DIRS=	build

INSTALLATION_DIRS+=	share/doc/snooper
PKG_DESTDIR_SUPPORT=	destdir

post-extract:
	${RM} ${WRKSRC}/build/.depend

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/snooper

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
