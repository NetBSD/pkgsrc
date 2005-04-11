# $NetBSD: Makefile,v 1.11 2005/04/11 21:47:24 tv Exp $

DISTNAME=	grun-0.9.2
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://www.geocities.com/ResearchTriangle/Facility/1468/sg/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	${MASTER_SITES}/grun.html
COMMENT=	GTK+ based Run dialog

USE_X11=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
PTHREAD_OPTS+=		require

post-install:
	${MV} ${LOCALBASE}/man/man1/grun.1x ${LOCALBASE}/man/man1/grun.1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
