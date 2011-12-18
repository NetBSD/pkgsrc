# $NetBSD: Makefile,v 1.15 2011/12/18 23:08:29 sbd Exp $
#

DISTNAME=		netris-0.52
PKGREVISION=		2
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
CONFIGURE_ARGS+=	${!empty(CFLAGS):?--cextra ${CFLAGS:Q}:}
CONFIGURE_ARGS+=	${!empty(LDFLAGS):?--lextra ${LDFLAGS:Q}:}

.include "options.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netris ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/netris
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DESTDIR}${PREFIX}/share/doc/netris
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/netris
	${INSTALL_DATA} ${WRKSRC}/robot_desc ${DESTDIR}${PREFIX}/share/doc/netris

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
