# $NetBSD: Makefile,v 1.18 2012/10/03 00:02:45 asau Exp $
#

DISTNAME=	tirc-1.2
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.mayn.de/pub/really_old_stuff/unix/network/irc/tirc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://home.mayn.de/jean-luc/alt/tirc/
COMMENT=	Token's 'Internet Relay Chat' Client

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+="--with-ansi-colours"

LIBS.SunOS+=	-lnsl -lsocket

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/tirc

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

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
	${INSTALL_DATA} ${WRKSRC}/dot.tircrc ${DESTDIR}${PREFIX}/share/tirc/tircrc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
