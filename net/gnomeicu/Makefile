# $NetBSD: Makefile,v 1.4 2001/02/17 18:18:55 wiz Exp $

DISTNAME=	gnomeicu-0.93
CATEGORIES=	net gnome
MASTER_SITES=	ftp://gnomeicu.gdev.net/pub/gnomeicu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://gnomeicu.gdev.net/
COMMENT=	GNOME ICQ client

DEPENDS+=	gdbm>=1.8.0:../../databases/gdbm
DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	YES

.include "../../mk/bsd.pkg.mk"
