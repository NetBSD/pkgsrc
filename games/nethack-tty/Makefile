# $NetBSD: Makefile,v 1.6 2000/03/27 08:54:56 tron Exp $

DISTNAME=		nethack-3.3.0
PKGNAME=		nethack-tty-3.3.0
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.win.tue.nl/pub/games/nethack.330/source/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.win.tue.nl/games/roguelike/nethack/

DEPENDS+=		nethack-lib-3.3.0:../nethack-lib

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh
ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-tty

PATCHDIR=		${PKGSRCDIR}/games/nethack-lib/patches

MD5_FILE=		${.CURDIR}/../nethack-lib/files/md5

post-extract:
	@${CHMOD} 755 ${WRKSRC}/sys/unix/setup.sh

post-patch:
	@${MV} ${WRKSRC}/include/config.h ${WRKSRC}/foo
	@${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' <${WRKSRC}/foo> ${WRKSRC}/include/config.h
	@${RM} -f ${WRKSRC}/foo

.include "../../mk/bsd.pkg.mk"
