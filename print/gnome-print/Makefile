# $NetBSD: Makefile,v 1.27 2000/06/01 11:23:40 rh Exp $
#

DISTNAME=		gnome-print-0.20
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-print/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html

DEPENDS+=		gnome-libs>=1.0.56:../../x11/gnome-libs
DEPENDS+=		libxml>=1.8.5:../../textproc/libxml
DEPENDS+=		ghostscript{,-nox11}-[6-9]*:../../print/ghostscript

USE_PKGLIBTOOL=		# defined
USE_X11BASE=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		GHOSTSCRIPT=${LOCALBASE}/bin/gs
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
#override HOME to avoid trying to install ${HOME}/.gnome
MAKE_ENV+=		HOME=${WRKSRC}

CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
