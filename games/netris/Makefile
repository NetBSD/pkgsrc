# $NetBSD: Makefile,v 1.6 2001/11/29 01:12:33 hubertf Exp $
#

DISTNAME=		netris-0.5
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

USE_GMAKE=		YES
HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./Configure

BUILD_DEFS+=		USE_INET6

# to get USE_INET6
.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=        --enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/netris ${PREFIX}/bin
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/netris
	@ ${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/netris
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/netris
	@ ${INSTALL_DATA} ${WRKSRC}/robot_desc ${PREFIX}/share/doc/netris

.include "../../mk/bsd.pkg.mk"
