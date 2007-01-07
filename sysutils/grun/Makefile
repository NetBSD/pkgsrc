# $NetBSD: Makefile,v 1.18 2007/01/07 09:14:11 rillig Exp $

DISTNAME=	grun-0.9.2
PKGREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	http://www.geocities.com/ResearchTriangle/Facility/1468/sg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITES}/grun.html
COMMENT=	GTK+ based Run dialog

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake
PTHREAD_OPTS+=		require

post-install:
	${MV} ${PREFIX}/${PKGMANDIR}/man1/grun.1x ${PREFIX}/${PKGMANDIR}/man1/grun.1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
