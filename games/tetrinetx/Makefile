# $NetBSD: Makefile,v 1.9 2018/01/14 15:26:48 rillig Exp $

DISTNAME=	tetrinetx-1.13.16+qirc-1.40c
PKGNAME=	tetrinetx-1.13.16
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://tetrinetx.sourceforge.net/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Server for an addictive 6 player tetris game

WRKSRC=		${WRKDIR}/${DISTNAME}
SHAREDIR=	${PREFIX}/share/tetrinetx
BINARY=		tetrix.netbsd
RCD_SCRIPTS=	tetrinetx

LIBS.SunOS+=	-lsocket -lnsl -lresolv

INSTALLATION_DIRS=	bin ${SHAREDIR}

do-build:
	cd ${WRKSRC}/src && \
	${CC} \
		${CPPFLAGS} -I${PREFIX}/include			\
		-DSHAREDIR=\"${SHAREDIR}\" -DPREFIX=\"${PREFIX}\"	\
		${CFLAGS} -fno-strength-reduce -Wall			\
		${LDFLAGS} -L${PREFIX}/lib -ladns ${LIBS}		\
		-o ../bin/${BINARY:Q} -Wl,-R${PREFIX}/lib		\
		main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${BINARY:Q} \
		${DESTDIR}${PREFIX}/bin/tetrix
	${INSTALL_DATA} ${WRKSRC}/bin/game.conf ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/game.secure ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/game.motd ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/game.pmotd ${DESTDIR}${SHAREDIR}

.include "../../net/adns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
