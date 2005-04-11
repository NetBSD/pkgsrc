# $NetBSD: Makefile,v 1.21 2005/04/11 21:46:50 tv Exp $

DISTNAME=	nap-1.4.4
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nap/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://nap.sourceforge.net/
COMMENT=	Terminal based Napster client similar to ircII

GNU_CONFIGURE=		YES

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
