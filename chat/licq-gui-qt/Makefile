# $NetBSD: Makefile,v 1.20 2006/01/24 07:31:58 wiz Exp $
#

DISTNAME=	licq-1.2.6
PKGNAME=	${DISTNAME:C/-/-gui-qt-/}
PKGREVISION=	6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	Qt GUI for licq

BUILDLINK_DEPENDS.qt3-libs?=    qt3-libs>=3.0
DEPENDS+=	licq-core-[0-9]*:../../chat/licq-core

.include "../../mk/bsd.prefs.mk"
.if ! exists(${X11BASE}/lib/libXss.so)
NOT_FOR_PLATFORM= NetBSD-*-*
.endif

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	# none
SHLIBTOOL_OVERRIDE=	libtool */libtool */*/libtool
WRKSRC=			${WRKDIR:=/${DISTNAME}/plugins/qt-gui}

INCOMPAT_CURSES=	NetBSD-1.4*-* NetBSD-1.5*-* NetBSD-1.6[-_.]*-* NetBSD-1.6[A-Q]-*

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
