# $NetBSD: Makefile,v 1.9 2001/12/30 21:19:12 wiz Exp $

DISTNAME=	nap-1.4.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nap/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gis.net/~nite/
COMMENT=	Terminal based Napster client similar to ircII

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
# newterm()
INCOMPAT_CURSES=	1.4[YZ] 1.4Z[A-C] 1.5 1.5.[12] 1.5[A-Z]

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nap ${PREFIX}/share/examples/nap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/nap.conf.dist \
	  ${PREFIX}/share/examples/nap/nap.conf

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
