# $NetBSD: Makefile,v 1.3 1999/10/15 00:03:55 hubertf Exp $
#

DISTNAME=	xarchon-0.42
CATEGORIES=	games x11
MASTER_SITES=	http://xarchon.seul.org/ \
		ftp://xarchon.seul.org/pub/xarchon/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://xarchon.seul.org/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	gtk+-1.2.2:../../x11/gtk
DEPENDS+=	glib-1.2.2:../../devel/glib
DEPENDS+=	esound-0.2.8:../../audio/esound

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xpm-prefix=${X11BASE} \
		--with-gtk-prefix=${X11BASE} \
		--with-esd-prefix=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
