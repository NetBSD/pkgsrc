# $NetBSD: Makefile,v 1.1.1.1 2003/04/24 23:57:36 hubertf Exp $
#

DISTNAME=	licq-1.2.6
PKGNAME=	${DISTNAME:C/-/-gui-qt-/}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	Qt GUI for licq

DEPENDS+=	licq-core-[0-9]*:../licq-core

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR:=/${DISTNAME}/plugins/qt-gui}

BUILDLINK_DEPENDS.qt3-libs?=    qt3-libs>=3
USE_NCURSES=	yes	# really use ncurses!

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
