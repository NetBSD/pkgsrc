# $NetBSD: Makefile,v 1.1.1.1 2002/10/18 09:36:01 rh Exp $
#

DISTNAME=	Gorm-0.1.9
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Graphical user interface builder for GNUstep

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES
MAKEFILE=	GNUmakefile
NO_CONFIGURE=	YES

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
