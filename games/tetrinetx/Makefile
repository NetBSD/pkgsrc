# $NetBSD: Makefile,v 1.5 2008/03/04 06:59:06 jlam Exp $

DISTNAME=	tetrinetx-1.13.16+qirc-1.40c
PKGNAME=	tetrinetx-1.13.16
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://tetrinetx.sourceforge.net/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Server for an addictive 6 player tetris game

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}
SHAREDIR=	${PREFIX}/share/tetrinetx
BINARY=		tetrix.netbsd
RCD_SCRIPTS=	tetrinetx

LIBS.SunOS+=	-lsocket -lnsl -lresolv

do-build:
	cd ${WRKSRC:Q}/src && \
	${CC} \
		${CPPFLAGS} -I${PREFIX:Q}/include			\
		-DSHAREDIR=\"${SHAREDIR:Q}\" -DPREFIX=\"${PREFIX:Q}\"	\
		${CFLAGS} -fno-strength-reduce -Wall			\
		${LDFLAGS} -L${PREFIX:Q}/lib -ladns ${LIBS}		\
		-o ../bin/${BINARY:Q} -Wl,-R${PREFIX:Q}/lib		\
		main.c

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}
	${INSTALL_PROGRAM} ${WRKSRC:Q}/bin/${BINARY:Q} \
		${DESTDIR}${PREFIX:Q}/bin/tetrix
	${INSTALL_DATA} ${WRKSRC:Q}/bin/game.conf ${DESTDIR}${SHAREDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/bin/game.secure ${DESTDIR}${SHAREDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/bin/game.motd ${DESTDIR}${SHAREDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/bin/game.pmotd ${DESTDIR}${SHAREDIR:Q}

.include "../../net/adns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
