# $NetBSD: Makefile,v 1.13 2005/06/01 18:03:22 jlam Exp $

DISTNAME=	grun-0.9.2
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://www.geocities.com/ResearchTriangle/Facility/1468/sg/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	${MASTER_SITES}/grun.html
COMMENT=	GTK+ based Run dialog

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
PTHREAD_OPTS+=		require

post-install:
	${MV} ${LOCALBASE}/man/man1/grun.1x ${LOCALBASE}/man/man1/grun.1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
