# $NetBSD: Makefile,v 1.23 2000/05/07 02:11:17 jlam Exp $
#

DISTNAME=		gnome-print-0.18
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-print/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html

DEPENDS+=		gnome-libs>=1.0.56:../../x11/gnome-libs
DEPENDS+=		libxml>=1.8.5:../../textproc/libxml
DEPENDS+=		ghostscript{,-nox11,-x11}-[0-9]*:../../print/ghostscript-x11

USE_LIBTOOL=		# defined
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
