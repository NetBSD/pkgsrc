# $NetBSD: Makefile,v 1.24 2005/04/11 21:45:17 tv Exp $

DISTNAME=	Gorm-0.9.2
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Graphical user interface builder for GNUstep

USE_X11=		yes
NO_CONFIGURE=		yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
