# $NetBSD: Makefile,v 1.3 1998/12/31 13:20:54 tv Exp $
#

DISTNAME=		nethack-3.2.2
PKGNAME=		nethack-x11-3.2.2
CATEGORIES=		games x11
MASTER_SITES=		http://pinky.wtower.com/nethack/sources/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.win.tue.nl/games/roguelike/nethack/

#DEPENDS+=		nethack-lib-3.2.2:../nethack-lib
#DEPENDS+=		xpm-3.4k:../../graphics/xpm

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	sys/unix/setup.sh
ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-x11

PATCHFILES+=		${PKGSRCDIR}/games/nethack-lib/patches/patch-*
ALLFILES=		${DISTFILES}	# don't checksum shared patches

post-patch:
	@${MV} ${WRKSRC}/include/config.h ${WRKSRC}/foo
	@${SED} -e 's@XXXLOCALBASEXXX@${LOCALBASE}@g' <${WRKSRC}/foo> ${WRKSRC}/include/config.h
	@${RM} -f ${WRKSRC}/foo

.include "../../mk/bsd.pkg.mk"
