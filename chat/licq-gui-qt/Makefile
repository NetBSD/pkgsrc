# $NetBSD: Makefile,v 1.3 2003/05/05 19:05:09 jmmv Exp $
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

DEPENDS+=	licq-core-[0-9]*:../licq-core

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR:=/${DISTNAME}/plugins/qt-gui}

USE_NCURSES=	yes	# really use ncurses!

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
