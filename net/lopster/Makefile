# $NetBSD: Makefile,v 1.6 2003/05/02 11:56:08 wiz Exp $
#

DISTNAME=	lopster-1.2.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lopster/}

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://lopster.sourceforge.net/
COMMENT=	Yet another Gtk+ Napster clone

DEPENDS+=	glib>=1.2.10nb5:../../devel/glib
DEPENDS+=	gtk+>=1.2.10nb4:../../x11/gtk

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	# defined
USE_INTL=	yes
CC+=		-I${LOCALBASE}/include	# libintl headers

post-extract:
	${RM} -fr ${WRKSRC}/intl

.include "../../mk/bsd.pkg.mk"
