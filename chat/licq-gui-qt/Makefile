# $NetBSD: Makefile,v 1.7 2003/07/17 21:26:02 grant Exp $
#

DISTNAME=	licq-1.2.6
PKGNAME=	${DISTNAME:C/-/-gui-qt-/}
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
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

PATCHDIR=	${.CURDIR}/../licq-gui-console/patches
DISTINFO_FILE=	${.CURDIR}/../licq-gui-console/distinfo

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
