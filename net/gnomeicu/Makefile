# $NetBSD: Makefile,v 1.2 2000/08/06 15:27:36 tron Exp $

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

.include "../../mk/bsd.pkg.mk"
