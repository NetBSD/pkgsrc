# $NetBSD: Makefile,v 1.8 2000/07/17 15:37:15 agc Exp $
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_FLAGS+=     	CC=gcc CPPFLAGS=
.endif

pre-configure:
	@${CHMOD} 755 ${WRKSRC}/sys/unix/setup.sh

post-patch:
	@${MV} ${WRKSRC}/include/config.h ${WRKSRC}/config.h-pre
	@${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g'				\
		-e 's|@GZIP_PROGRAM@|'`${ECHO} ${GZIP_CMD} | ${AWK} '{ print $$1 }'`'|g' \
		${WRKSRC}/config.h-pre > ${WRKSRC}/include/config.h
	@${RM} -f ${WRKSRC}/config.h-pre

post-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|' ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

.include "../../mk/bsd.pkg.mk"
