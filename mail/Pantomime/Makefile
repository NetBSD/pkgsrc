# $NetBSD: Makefile,v 1.9 2004/01/24 13:55:30 grant Exp $
#

DISTNAME=	Pantomime-1.1.1
PKGREVISION=			2
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/pantomime/
COMMENT=	Objective-C mail system class library

WRKSRC=			${WRKDIR}/Pantomime
NO_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
MAKEFILE=		GNUmakefile
MAKE_ENV+=		ADDITIONAL_CPPFLAGS=-DMKDIR

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
