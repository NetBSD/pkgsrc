# $NetBSD: Makefile,v 1.1.1.1 2002/09/28 00:02:06 rh Exp $
#

DISTNAME=	gnustep-examples-0.9.7
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Some GUI programming examples for GNUstep

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES
MAKEFILE=	GNUmakefile
NO_CONFIGURE=	YES

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
