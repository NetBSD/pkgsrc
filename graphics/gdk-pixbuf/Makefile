# $NetBSD: Makefile,v 1.6 2000/07/05 23:49:30 hubertf Exp $
#

DISTNAME=		gdk-pixbuf-0.8.0nb1
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gdk-pixbuf/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		gnome-libs>=1.0.53:../../x11/gnome-libs

GNU_CONFIGURE=		# defined
USE_X11BASE=		# defined
USE_GMAKE=		# defined

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		X11BASE="${X11BASE}"
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

.include "../../mk/bsd.prefs.mk"
.if (${OBJECT_FMT} == "ELF")
PLIST_SRC=	${PKGDIR}/PLIST.elf
.endif
PLIST_SRC+=	${PKGDIR}/PLIST.mi

.include "../../mk/bsd.pkg.mk"
