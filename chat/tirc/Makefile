# $NetBSD: Makefile,v 1.3 2002/10/25 17:20:08 wiz Exp $
#

DISTNAME=	tirc-1.2
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.mayn.de/pub/unix/network/irc/tirc/

MAINTAINER=	packages@netbsd.org
COMMENT=	Token's 'Internet Relay Chat' Client

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+="--with-ansi-colours"

post-patch:
	${SED} "s,/usr/local,${PREFIX},g" ${WRKSRC}/tirc.1		\
		> ${WRKSRC}/tirc.1.done
	${MV} ${WRKSRC}/tirc.1.done ${WRKSRC}/tirc.1

	${SED} "s,/usr/local/share/tircrc,${PREFIX}/share/tirc/tircrc,g"\
		${WRKSRC}/main.c > ${WRKSRC}/main.c.done
	${MV} ${WRKSRC}/main.c.done ${WRKSRC}/main.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/tirc
	${INSTALL_DATA} ${WRKSRC}/dot.tircrc ${PREFIX}/share/tirc/tircrc

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
