# $NetBSD: Makefile,v 1.1.1.1 2001/11/11 20:16:10 damon Exp $

DISTNAME=	Guppi-0.40.0
PKGNAME=	guppi-0.40.0
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/Guppi/}

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://www.gnome.org/projects/guppi/
COMMENT=	gnome plotting tool

DEPEND+=	bonobo>=1.0.8:../../devel/bonobo
DEPEND+=	gtk+>=1.2.0:../../x11/gtk
DEPEND+=	gnome-print>=0.28:../../print/gnome-print
DEPEND+=	gnumeric>=0.75:../../math/gnumeric

USE_GMAKE=		#defined
USE_X11BASE=		#defined
HAS_CONFIGURE=		#defined
CONFIGURE_ARGS+=	--prefix ${PREFIX}
PLIST_SUBST+=		MKDIR='${MKDIR}'

.include "../../mk/bsd.pkg.mk"
