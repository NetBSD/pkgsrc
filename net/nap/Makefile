# $NetBSD: Makefile,v 1.6 2001/06/11 06:34:46 jlam Exp $

DISTNAME=	nap-1.4.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nap/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gis.net/~nite/
COMMENT=	Terminal based Napster client similar to ircII

DEPENDS+=	ncurses>=5.0:../../devel/ncurses

GNU_CONFIGURE=	YES
CPPFLAGS+=	-I${LOCALBASE}/include

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nap ${PREFIX}/share/examples/nap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/nap.conf.dist \
	  ${PREFIX}/share/examples/nap/nap.conf

.include "../../mk/bsd.pkg.mk"
