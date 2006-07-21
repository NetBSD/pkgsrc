# $NetBSD: Makefile,v 1.17 2006/07/21 05:32:40 rillig Exp $
#

DISTNAME=	Pantomime-1.1.2
PKGREVISION=	3
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/pantomime/
COMMENT=	Objective-C mail system class library

USE_LANGUAGES=	c objc

WRKSRC=		${WRKDIR}/Pantomime
NO_CONFIGURE=	yes
MAKE_ENV+=	ADDITIONAL_CPPFLAGS=-DMKDIR

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
