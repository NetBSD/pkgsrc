# $NetBSD: Makefile,v 1.7 2001/12/25 17:40:26 wiz Exp $

DISTNAME=	nap-1.4.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nap/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gis.net/~nite/
COMMENT=	Terminal based Napster client similar to ircII

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nap ${PREFIX}/share/examples/nap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/nap.conf.dist \
	  ${PREFIX}/share/examples/nap/nap.conf

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
