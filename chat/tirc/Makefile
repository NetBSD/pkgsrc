# $NetBSD: Makefile,v 1.11 2004/04/11 06:07:52 snj Exp $
#

DISTNAME=	tirc-1.2
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.mayn.de/pub/unix/network/irc/tirc/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://home.mayn.de/jean-luc/alt/tirc/
COMMENT=	Token's 'Internet Relay Chat' Client

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+="--with-ansi-colours"

LIBS.SunOS+=	-lnsl -lsocket

post-patch:
	${SED} "s,/usr/local,${PREFIX},g" ${WRKSRC}/tirc.1		\
		> ${WRKSRC}/tirc.1.done
	${MV} ${WRKSRC}/tirc.1.done ${WRKSRC}/tirc.1

	${SED} "s,/usr/local/share/tircrc,${PREFIX}/share/tirc/tircrc,g"\
		${WRKSRC}/main.c > ${WRKSRC}/main.c.done
	${MV} ${WRKSRC}/main.c.done ${WRKSRC}/main.c
.if exists(/usr/include/sys/queue.h)
	${RM} ${WRKSRC}/sys/queue.h
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/tirc
	${INSTALL_DATA} ${WRKSRC}/dot.tircrc ${PREFIX}/share/tirc/tircrc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
