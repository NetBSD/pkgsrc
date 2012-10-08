# $NetBSD: Makefile,v 1.25 2012/10/08 12:19:01 asau Exp $
#

DISTNAME=	Pantomime-1.2.0pre3
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/pantomime/
COMMENT=	Objective-C mail system class library
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	objc

PRIVILEGED_STAGES+=	build
PRIVILEGED_STAGES+=	clean

WRKSRC=		${WRKDIR}/Pantomime
NO_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
MAKE_ENV+=	ADDITIONAL_CPPFLAGS=-DMKDIR
MAKE_FILE=	GNUmakefile

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
