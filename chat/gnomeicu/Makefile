# $NetBSD: Makefile,v 1.1.1.1 2001/02/26 18:43:18 wiz Exp $

DISTNAME=	gnomeicu-0.96
CATEGORIES=	chat gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnomeicu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://gnomeicu.sourceforge.net/
COMMENT=	GNOME ICQ client

DEPENDS+=	gdbm>=1.8.0:../../databases/gdbm
DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	YES

.include "../../mk/bsd.pkg.mk"
