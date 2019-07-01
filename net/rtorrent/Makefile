# $NetBSD: Makefile,v 1.74 2019/07/01 04:08:42 ryoon Exp $

DISTNAME=	rtorrent-0.9.7
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://rtorrent.net/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rakshasa/rtorrent
COMMENT=	Ncurses based torrent client with support for sessions
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_NCURSES=		yes # chgat
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "alpha" || \
    ${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "powerpc" || \
    ${MACHINE_ARCH} == "x86_64"
GCC_REQD+=		4.1.3
.else
GCC_REQD+=		4.2.1
.endif

.include "../../mk/pthread.buildlink3.mk"
LDFLAGS+=	${PTHREAD_LDFLAGS}

.include "options.mk"

# See http://libtorrent.rakshasa.no/ticket/77
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.0.*)
CXXFLAGS+=	-fpermissive -fno-strength-reduce -fno-thread-jumps \
		-fno-inline -fforce-addr
.endif

.if !empty(CC_VERSION:Mgcc-*) && !empty(MACHINE_ARCH:Mi?86)
CXXFLAGS+=	-march=i486
.endif

INSTALLATION_DIRS=	share/examples/rtorrent

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc \
		${DESTDIR}${PREFIX}/share/examples/rtorrent

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libtorrent/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
