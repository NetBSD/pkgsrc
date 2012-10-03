# $NetBSD: Makefile,v 1.41 2012/10/03 00:02:40 asau Exp $
#

DISTNAME=	licq-1.3.5
PKGNAME=	${DISTNAME:C/-/-gui-qt-/}
PKGREVISION=	7
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	Qt GUI for licq

BUILDLINK_API_DEPENDS.qt3-libs?=    qt3-libs>=3.0
DEPENDS+=	licq-core-[0-9]*:../../chat/licq-core

.include "../../mk/bsd.prefs.mk"

DISTINFO_FILE=		${.CURDIR}/../../chat/licq-core/distinfo
PATCHDIR=		${.CURDIR}/../../chat/licq-core/patches

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty
OVERRIDE_DIRDEPTH=	3
CONFIGURE_DIRS=		plugins/qt-gui

INCOMPAT_CURSES=	NetBSD-1.4*-* NetBSD-1.5*-* NetBSD-1.6[-_.]*-* NetBSD-1.6[A-Q]-*

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
