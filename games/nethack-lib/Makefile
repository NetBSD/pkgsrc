# $NetBSD: Makefile,v 1.6 2000/04/14 14:06:52 pooka Exp $
#

DISTNAME=		nethack-3.3.0
PKGNAME=		nethack-lib-3.3.0
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.win.tue.nl/pub/games/nethack.330/source/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.win.tue.nl/games/roguelike/nethack/

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh
ALL_TARGET=		datastuff
INSTALL_TARGET=		manpages install-dat

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL

pre-configure:
	@${CHMOD} 755 ${WRKSRC}/sys/unix/setup.sh

post-patch:
	@${MV} ${WRKSRC}/include/config.h ${WRKSRC}/foo
	@${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' <${WRKSRC}/foo> ${WRKSRC}/include/config.h
	@${RM} -f ${WRKSRC}/foo

post-build:
	@cd ${PKGDIR} ; \
	${SED} -e 's#@PREFIX@#${PREFIX}#' < DEINSTALL > ${DEINSTALL_FILE}

.include "../../mk/bsd.pkg.mk"
