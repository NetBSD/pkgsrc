# $NetBSD: Makefile,v 1.7 2004/03/08 19:40:39 jmmv Exp $
#

DISTNAME=		gnome-core-1.4.2
PKGNAME=		${DISTNAME:S/core/pixmaps/}
PKGREVISION=		1
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-core/1.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Pixmaps for gnome-core

DEPENDS+=		xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

.include "../../mk/bsd.prefs.mk"

CONFLICTS=		gnome-core<1.4.2
.if (${LOCALBASE} == ${X11PREFIX})
CONFLICTS+=		gnome2-pixmaps-[0-9]*
.endif

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

DSTDIR=			${PREFIX}/share/pixmaps

do-install:
	${INSTALL_DATA_DIR} ${DSTDIR}/tiles
	cd ${WRKSRC}/pixmaps &&					\
	for i in *.png *.xpm ; do				\
		${INSTALL_DATA} $$i ${DSTDIR} ;			\
	done &&							\
	for i in tile-* ; do					\
		${LN} ${DSTDIR}/$$i ${DSTDIR}/tiles ;		\
	done

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
