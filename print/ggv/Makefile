# $NetBSD: Makefile,v 1.16 2000/06/01 11:23:40 rh Exp $
#

DISTNAME=	ggv-0.50
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/ggv/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
DEPENDS+=	ghostscript-[6-9]*:../../print/ghostscript
DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_PKGLIBTOOL=	YES
USE_X11BASE=	YES

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
