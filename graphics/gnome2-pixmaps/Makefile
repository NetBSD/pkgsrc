# $NetBSD: Makefile,v 1.3 2002/09/15 05:58:57 rh Exp $
#

DISTNAME=		gnome-desktop-2.0.8
PKGNAME=		${DISTNAME:S/-desktop/2-pixmaps/}
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.1/sources/gnome-desktop/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Pixmaps for gnome-core

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=		gnome-core<1.4.2
.if (${LOCALBASE} == ${X11PREFIX})
CONFLICTS+=		gnome-pixmaps-[0-9]*
.else
CONFLICTS+=		gnome-pixmaps-2.0.8
.endif

USE_BUILDLINK_ONLY=	YES
USE_X11=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

DSTDIR=			${PREFIX}/share/pixmaps

do-install:
	cd ${WRKSRC}/pixmaps &&					\
	for i in *.png *.xpm ; do				\
		${INSTALL_DATA} $$i ${DSTDIR} ;			\
	done

.include "../../archivers/bzip2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
