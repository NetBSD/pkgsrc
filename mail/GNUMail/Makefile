# $NetBSD: Makefile,v 1.7 2003/12/05 11:27:01 adam Exp $
#

DISTNAME=	GNUMail-1.1.1
WRKSRC=		${WRKDIR}/GNUMail
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/gnumail/
COMMENT=	GNUstep clone of NeXT's Mail.app application

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES
NO_CONFIGURE=		YES
MAKEFILE=		GNUmakefile

.include "../../mail/Pantomime/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
