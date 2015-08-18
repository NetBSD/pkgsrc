# $NetBSD: Makefile,v 1.27 2015/08/18 07:31:15 wiz Exp $

DISTNAME=	nap-1.4.4
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nap.sourceforge.net/
COMMENT=	Terminal based Napster client similar to ircII

GNU_CONFIGURE=		YES

# newterm()
INCOMPAT_CURSES=	NetBSD-1.4*-*
INCOMPAT_CURSES+=	NetBSD-1.5-* NetBSD-1.5.*-* NetBSD-1.5[A-Z]-*

INSTALLATION_DIRS+=	share/doc/nap share/examples/nap

LDFLAGS.SunOS+=		-lsocket -lnsl

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/nap.conf.dist \
		${DESTDIR}${PREFIX}/share/examples/nap/nap.conf

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
