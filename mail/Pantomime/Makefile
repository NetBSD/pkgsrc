# $NetBSD: Makefile,v 1.19 2006/09/22 07:08:16 rillig Exp $
#

DISTNAME=	Pantomime-1.1.2
PKGREVISION=	3
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/pantomime/
COMMENT=	Objective-C mail system class library

USE_LANGUAGES=	objc

WRKSRC=		${WRKDIR}/Pantomime
NO_CONFIGURE=	yes
MAKE_ENV+=	ADDITIONAL_CPPFLAGS=-DMKDIR
MAKE_FILE=	GNUmakefile

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
