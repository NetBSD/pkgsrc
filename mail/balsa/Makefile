# $NetBSD: Makefile,v 1.1.1.1 1999/12/12 18:13:53 rh Exp $
#

DISTNAME=	balsa-0.4.9.5
CATEGORIES=	mail gnome
MASTER_SITES=	ftp://ftp.balsa.net/pub/balsa/ \
		ftp://ftp.univie.ac.at/systems/linux/metalab/X11/gtkbuffet/apps/balsa/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.balsa.net/

DEPENDS+=	pth-*:../../devel/pth
DEPENDS+=	libproplist-*:../../devel/libproplist
DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"
