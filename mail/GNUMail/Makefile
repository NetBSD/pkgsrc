# $NetBSD: Makefile,v 1.10 2004/01/23 21:50:46 jmmv Exp $
#

DISTNAME=	GNUMail-1.1.1
PKGREVISION=			2
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/gnumail/
COMMENT=	GNUstep clone of NeXT's Mail.app application

WRKSRC=			${WRKDIR}/GNUMail
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES
NO_CONFIGURE=		YES
MAKEFILE=		GNUmakefile

.include "../../mail/Pantomime/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
