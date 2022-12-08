# $NetBSD: Makefile,v 1.17 2022/12/08 08:51:55 vins Exp $
#

DISTNAME=	xwpe-1.5.30a
CATEGORIES=	editors
MASTER_SITES=	http://www.identicalsoftware.com/xwpe/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://www.identicalsoftware.com/xwpe/
COMMENT=	Programming environment for UNIX systems
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
INCOMPAT_CURSES+=	NetBSD-[0-5].*-* #tigetstr
FAKE_NCURSES=		yes

BUILD_TARGET=		# the one from the Makefile

BUILDLINK_DEPMETHOD.libXt?=	build

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

post-install:
# Run acme as a standalone application.
	${INSTALL_DATA} ${FILESDIR}/xwpe.desktop	\
	   ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/xwpe.xpm		\
	   ${DESTDIR}${PREFIX}/share/pixmaps

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
