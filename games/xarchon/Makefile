# $NetBSD: Makefile,v 1.1.1.1 1999/10/14 23:32:16 hubertf Exp $
#

DISTNAME=	xarchon-0.42
CATEGORIES=	games x11
MASTER_SITES=	http://xarchon.seul.org/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://xarchon.seul.org/

#DEPENDS+=	xpm
#DEPENDS+=	gtk
#DEPENDS+=	glib
#DEPENDS+=	esd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xpm-prefix=${X11BASE} \
		--with-gtk-prefix=${X11BASE} \
		--with-esd-prefix=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
