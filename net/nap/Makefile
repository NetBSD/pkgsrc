# $NetBSD: Makefile,v 1.10 2002/01/24 12:04:54 tron Exp $

DISTNAME=	nap-1.4.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nap/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gis.net/~nite/
COMMENT=	Terminal based Napster client similar to ircII

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
# newterm()
INCOMPAT_CURSES=	1.4* 1.5 1.5_* 1.5.[1-9]* 1.5[A-Z]

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nap ${PREFIX}/share/examples/nap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/nap.conf.dist \
	  ${PREFIX}/share/examples/nap/nap.conf

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
