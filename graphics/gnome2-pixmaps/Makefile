# $NetBSD: Makefile,v 1.23 2005/03/22 16:09:27 jmmv Exp $
#

DISTNAME=		gnome-desktop-2.10.0
PKGNAME=		${DISTNAME:S/-desktop/2-pixmaps/}
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-desktop/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Pixmaps for gnome-core

.include "../../mk/bsd.prefs.mk"

.if (${LOCALBASE} == ${X11PREFIX})
CONFLICTS+=		gnome-core<1.4.2
CONFLICTS+=		gnome-pixmaps-[0-9]*
.else
CONFLICTS+=		gnome-pixmaps-2.0.8
.endif

USE_DIRS+=		xdg-1.1
USE_X11=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES
NO_BUILDLINK=		# defined

DSTDIR=			${PREFIX}/share/pixmaps

do-install:
	cd ${WRKSRC}/pixmaps &&					\
	for i in *.png *.xpm ; do				\
		${INSTALL_DATA} $$i ${DSTDIR} ;			\
	done

.include "../../mk/bsd.pkg.mk"
