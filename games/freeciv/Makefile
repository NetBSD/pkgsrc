# $NetBSD: Makefile,v 1.11 1999/08/28 09:43:09 rh Exp $
#

DISTNAME=	freeciv-1.8.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/freeciv/stable_version/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.freeciv.org/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	gtk+-1.2.4:../../x11/gtk
DEPENDS+=	imlib-1.9.4:../../graphics/imlib

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
