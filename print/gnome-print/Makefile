# $NetBSD: Makefile,v 1.19 2000/04/16 15:07:42 rh Exp $
#

DISTNAME=		gnome-print-0.18
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-print/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html

DEPENDS+=		gnome-libs>=1.0.56:../../x11/gnome-libs
DEPENDS+=		libxml>=1.8.5:../../textproc/libxml
DEPENDS+=		ghostscript-5.*:../../print/ghostscript5

USE_LIBTOOL=		# defined
USE_X11BASE=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		GHOSTSCRIPT=${LOCALBASE}/bin/gstty
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
