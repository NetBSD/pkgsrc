# $NetBSD: Makefile,v 1.4 2002/01/18 13:39:03 martti Exp $
#

DISTNAME=	lopster-1.0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lopster/}

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://lopster.sourceforge.net/
COMMENT=	Yet another Gtk+ Napster clone

DEPENDS+=	glib>=1.2.0:../../devel/glib
DEPENDS+=	gtk+>=1.2.8:../../x11/gtk

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	# defined
USE_INTL=	yes
CC+=		-I${LOCALBASE}/include	# libintl headers

post-extract:
	${RM} -fr ${WRKSRC}/intl

.include "../../mk/bsd.pkg.mk"
