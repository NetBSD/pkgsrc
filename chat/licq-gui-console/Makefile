# $NetBSD: Makefile,v 1.2 2003/05/11 08:02:32 jmc Exp $
#

DISTNAME=	licq-1.2.6
PKGNAME=	${DISTNAME:C/-/-gui-console-/}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	Curses GUI for licq

DEPENDS+=	licq-core-[0-9]*:../licq-core

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR:=/${DISTNAME}/plugins/console}

USE_NCURSES=	yes	# really use ncurses!

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
