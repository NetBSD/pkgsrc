# $NetBSD: Makefile,v 1.17 2000/04/07 08:43:01 rh Exp $
#

DISTNAME=	gnome-print-0.16
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-print/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.levien.com/gnome/print-arch.html

DEPENDS+=	gnome-libs>=1.0.56:../../x11/gnome-libs
DEPENDS+=	libxml>=1.8.5:../../textproc/libxml
DEPENDS+=	ghostscript-5.*:../../print/ghostscript5

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
