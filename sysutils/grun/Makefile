# $NetBSD: Makefile,v 1.2 2002/06/01 23:53:34 grant Exp $

DISTNAME=	grun-0.9.2
CATEGORIES=	misc
MASTER_SITES=	http://www.geocities.com/ResearchTriangle/Facility/1468/sg/

MAINTAINER=	epg@pretzelnet.org
HOMEPAGE=	${MASTER_SITES}/grun.html
COMMENT=	GTK+ based Run dialog

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_PTHREAD=		native pth-syscall pth

post-install:
	${MV} ${LOCALBASE}/man/man1/grun.1x ${LOCALBASE}/man/man1/grun.1

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
