# $NetBSD: Makefile,v 1.1.1.1 2002/09/14 06:57:33 rh Exp $
#

DISTNAME=		gnome-desktop-2.0.8
PKGNAME=		${DISTNAME:S/desktop/pixmaps/}
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.1/sources/gnome-desktop/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Pixmaps for gnome-core

CONFLICTS=		gnome-core<1.4.2

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
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
