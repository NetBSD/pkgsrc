# $NetBSD: Makefile,v 1.13 2004/01/23 21:50:43 jmmv Exp $
#

DISTNAME=	Gorm-0.4.0
PKGREVISION=	2
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Graphical user interface builder for GNUstep

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
MAKEFILE=		GNUmakefile
NO_CONFIGURE=		YES

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
