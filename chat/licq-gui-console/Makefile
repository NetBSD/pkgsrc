# $NetBSD: Makefile,v 1.8 2003/09/27 17:07:35 grant Exp $
#

DISTNAME=	licq-1.2.6
PKGNAME=	${DISTNAME:C/-/-gui-console-/}
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	Curses GUI for licq

DEPENDS+=	licq-core-[0-9]*:../licq-core

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR:=/${DISTNAME}/plugins/console}

INCOMPAT_CURSES=	NetBSD-1.4*-* NetBSD-1.5*-* NetBSD-1.6[-_.]*-* NetBSD-1.6[A-Q]-*

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
