# $NetBSD: Makefile,v 1.31 2020/03/20 11:58:08 nia Exp $

DISTNAME=	nap-1.4.4
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nap.sourceforge.net/
COMMENT=	Terminal based Napster client similar to ircII

GNU_CONFIGURE=		YES
FAKE_NCURSES=		yes

INSTALLATION_DIRS+=	share/doc/nap share/examples/nap

LDFLAGS.SunOS+=		-lsocket -lnsl

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/nap.conf.dist \
		${DESTDIR}${PREFIX}/share/examples/nap/nap.conf

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
