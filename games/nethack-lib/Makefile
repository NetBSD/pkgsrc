# $NetBSD: Makefile,v 1.2 1998/09/24 16:53:20 garbled Exp $
#

DISTNAME=		nethack-3.2.2
PKGNAME=		nethack-lib-3.2.2
CATEGORIES=		games
MASTER_SITES=		http://pinky.wtower.com/nethack/sources/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.win.tue.nl/games/roguelike/nethack/

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	sys/unix/setup.sh
ALL_TARGET=		datastuff
INSTALL_TARGET=		manpages install-dat

post-patch:
	@${MV} ${WRKSRC}/include/config.h ${WRKSRC}/foo
	@${SED} -e 's@XXXLOCALBASEXXX@$(LOCALBASE)@g' <${WRKSRC}/foo> ${WRKSRC}/include/config.h
	@${RM} -f ${WRKSRC}/foo

.include "../../mk/bsd.pkg.mk"
