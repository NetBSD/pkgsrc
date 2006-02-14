# $NetBSD: Makefile,v 1.1.1.1 2006/02/14 17:03:54 rillig Exp $

DISTNAME=	tetrinetx-1.13.16+qirc-1.40c
PKGNAME=	tetrinetx-1.13.16
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

do-build:
	cd ${WRKSRC:Q}/src && \
	${CC} \
		${CPPFLAGS} -I${LOCALBASE:Q}/include			\
		-DSHAREDIR=\"${SHAREDIR:Q}\" -DPREFIX=\"${PREFIX:Q}\"	\
		${CFLAGS} -fno-strength-reduce -Wall			\
		${LDFLAGS} -L${LOCALBASE:Q}/lib -ladns ${LIBS}		\
		-o ../bin/${BINARY:Q} -Wl,-R${LOCALBASE:Q}/lib		\
		main.c

do-install:
	${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/examples/rc.d
	${INSTALL_PROGRAM} ${WRKSRC:Q}/bin/${BINARY:Q} ${PREFIX:Q}/bin/tetrix
	${INSTALL_DATA} ${WRKSRC:Q}/bin/game.conf ${SHAREDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/bin/game.secure ${SHAREDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/bin/game.motd ${SHAREDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/bin/game.pmotd ${SHAREDIR:Q}
	${INSTALL_SCRIPT} ${FILESDIR:Q}/tetrinetx ${PREFIX:Q}/share/examples/rc.d/

.include "../../net/adns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
