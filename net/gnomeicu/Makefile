# $NetBSD: Makefile,v 1.3 2000/11/27 06:34:49 tron Exp $

DISTNAME=	gnomeicu-0.93
CATEGORIES=	net gnome
MASTER_SITES=	ftp://gnomeicu.gdev.net/pub/gnomeicu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://gnomeicu.gdev.net/

DEPENDS+=	gdbm>=1.8.0:../../databases/gdbm
DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	YES

.include "../../mk/bsd.pkg.mk"
