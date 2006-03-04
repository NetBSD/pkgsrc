# $NetBSD: Makefile,v 1.17 2006/03/04 21:30:41 jlam Exp $

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
	${MV} ${PREFIX}/man/man1/grun.1x ${PREFIX}/man/man1/grun.1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
