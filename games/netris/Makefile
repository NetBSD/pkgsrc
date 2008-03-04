# $NetBSD: Makefile,v 1.13 2008/03/04 06:59:05 jlam Exp $
#

DISTNAME=		netris-0.52
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.netris.org/pub/netris/

PATCH_SITES=		ftp://ftp2.v6.linux.or.jp/pub/Linux/IPv6-2/netris/ \
			http://ftp2.v6.linux.or.jp/pub/Linux/IPv6-2/netris/
PATCHFILES=		netris-0.5-v6-19991206a.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		uebs@gmx.at
HOMEPAGE=		http://www.netris.org/
COMMENT=		Everybody's darling T*tris in a networked version

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./Configure

.include "options.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netris ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/netris
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DESTDIR}${PREFIX}/share/doc/netris
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/netris
	${INSTALL_DATA} ${WRKSRC}/robot_desc ${DESTDIR}${PREFIX}/share/doc/netris

.include "../../mk/bsd.pkg.mk"
