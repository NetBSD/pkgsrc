# $NetBSD: Makefile,v 1.1.1.1 2001/11/18 22:41:40 agc Exp $

DISTNAME=	grun-0.9.2
CATEGORIES=	misc
MASTER_SITES=	http://www.geocities.com/ResearchTriangle/Facility/1468/sg/

MAINTAINER=	epg@pretzelnet.org
HOMEPAGE=	${MASTER_SITES}/grun.html
COMMENT=	GTK+ based Run dialog

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES

post-install:
	${MV} ${LOCALBASE}/man/man1/grun.1x ${LOCALBASE}/man/man1/grun.1

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
