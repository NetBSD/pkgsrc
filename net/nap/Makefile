# $NetBSD: Makefile,v 1.18 2004/04/25 21:00:16 snj Exp $

DISTNAME=	nap-1.4.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nap/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://nap.sourceforge.net/
COMMENT=	Terminal based Napster client similar to ircII

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES

# newterm()
INCOMPAT_CURSES=	NetBSD-1.4*-*
INCOMPAT_CURSES+=	NetBSD-1.5-* NetBSD-1.5.*-* NetBSD-1.5[A-Z]-*

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nap ${PREFIX}/share/examples/nap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/nap.conf.dist \
		${PREFIX}/share/examples/nap/nap.conf

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
