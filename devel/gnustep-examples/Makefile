# $NetBSD: Makefile,v 1.10 2004/03/26 02:27:38 wiz Exp $
#

DISTNAME=	gnustep-examples-0.9.7
PKGREVISION=	7
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Some GUI programming examples for GNUstep

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
MAKEFILE=		GNUmakefile
NO_CONFIGURE=		YES

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
