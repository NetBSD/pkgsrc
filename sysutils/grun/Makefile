# $NetBSD: Makefile,v 1.7 2004/01/24 15:06:57 grant Exp $

DISTNAME=	grun-0.9.2
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.geocities.com/ResearchTriangle/Facility/1468/sg/

MAINTAINER=	epg@pretzelnet.org
HOMEPAGE=	${MASTER_SITES}/grun.html
COMMENT=	GTK+ based Run dialog

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
PTHREAD_OPTS+=		require

post-install:
	${MV} ${LOCALBASE}/man/man1/grun.1x ${LOCALBASE}/man/man1/grun.1

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
