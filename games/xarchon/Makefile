# $NetBSD: Makefile,v 1.4 1999/10/22 23:41:45 tron Exp $
#

DISTNAME=	xarchon-0.42
CATEGORIES=	games x11
MASTER_SITES=	http://xarchon.seul.org/ \
		ftp://xarchon.seul.org/pub/xarchon/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://xarchon.seul.org/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	esound-*:../../audio/esound

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xpm-prefix=${X11BASE} \
		--with-gtk-prefix=${X11BASE} \
		--with-esd-prefix=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
