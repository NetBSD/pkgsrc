# $NetBSD: Makefile,v 1.2 2002/09/15 05:40:42 rh Exp $
#

DISTNAME=		gnome-core-1.4.2
PKGNAME=		${DISTNAME:S/core/pixmaps/}
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-core/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Pixmaps for gnome-core

CONFLICTS=		gnome-core<1.4.2
.if (${LOCALBASE} == ${X11BASE})
CONFLICTS+=		gnome2-pixmaps-[0-9]*
.endif

USE_BUILDLINK_ONLY=	YES
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

.include "../../archivers/bzip2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
