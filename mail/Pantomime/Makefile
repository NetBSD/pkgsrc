# $NetBSD: Makefile,v 1.13 2004/10/03 00:12:52 tv Exp $
#

DISTNAME=	Pantomime-1.1.2
PKGREVISION=	2
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/pantomime/
COMMENT=	Objective-C mail system class library

WRKSRC=		${WRKDIR}/Pantomime
NO_CONFIGURE=	yes
USE_BUILDLINK3=	yes
MAKE_ENV+=	ADDITIONAL_CPPFLAGS=-DMKDIR

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
