# $NetBSD: Makefile,v 1.2 2001/02/17 18:19:05 wiz Exp $
#

DISTNAME=	lopster-0.9.7.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lopster/}

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://lopster.sourceforge.net/
COMMENT=	Yet another Gtk+ Napster clone

DEPENDS+=	glib>=1.2.0:../../devel/glib
DEPENDS+=	gtk+>=1.2.8:../../x11/gtk

USE_X11BASE=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	# defined

.include "../../mk/bsd.pkg.mk"
