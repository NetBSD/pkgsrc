# $NetBSD: Makefile,v 1.4 2003/05/06 23:07:42 hubertf Exp $
#

DISTNAME=	licq-1.2.6
PKGNAME=	${DISTNAME:C/-/-gui-qt-/}
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	Qt GUI for licq

BUILDLINK_DEPENDS.qt3-libs?=    qt3-libs>=3.0
DEPENDS+=	licq-core-[0-9]*:../licq-core

.include "../../mk/bsd.prefs.mk"
.if ! exists(${X11PREFIX}/lib/libXss.so)
NOT_FOR_PLATFORM= NetBSD-*-*
.endif

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR:=/${DISTNAME}/plugins/qt-gui}

USE_NCURSES=	yes	# really use ncurses!

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
