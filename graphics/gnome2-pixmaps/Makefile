# $NetBSD: Makefile,v 1.12 2003/12/14 22:10:53 xtraeme Exp $
#

DISTNAME=		gnome-desktop-2.4.1.1
PKGNAME=		${DISTNAME:S/-desktop/2-pixmaps/}
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-desktop/2.4/}
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

USE_BUILDLINK2=		YES
USE_X11=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

DSTDIR=			${PREFIX}/share/pixmaps

do-install:
	cd ${WRKSRC}/pixmaps &&					\
	for i in *.png *.xpm ; do				\
		${INSTALL_DATA} $$i ${DSTDIR} ;			\
	done

.include "../../mk/bsd.pkg.mk"
