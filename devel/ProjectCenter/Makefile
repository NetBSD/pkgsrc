# $NetBSD: Makefile,v 1.22 2006/02/05 23:08:38 joerg Exp $

DISTNAME=	ProjectCenter-0.4.3
PKGREVISION=	2
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/experience/ProjectCenter.html
COMMENT=	GNUstep Integrated Development Environment

NO_CONFIGURE=		yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
