# $NetBSD: Makefile,v 1.19 2025/06/02 12:54:30 vins Exp $
#

DISTNAME=	xwpe-1.5.30a
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.identicalsoftware.com/xwpe/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://www.identicalsoftware.com/xwpe/
COMMENT=	Programming environment for UNIX systems
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

BUILD_TARGET=		# the one from the Makefile

BUILDLINK_DEPMETHOD.libXt?=	build

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

post-install:
	${INSTALL_DATA} ${FILESDIR}/xwpe.desktop	\
	   ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/xwpe.xpm		\
	   ${DESTDIR}${PREFIX}/share/pixmaps

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
