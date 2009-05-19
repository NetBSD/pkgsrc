# $NetBSD: Makefile,v 1.24 2009/05/19 08:59:20 wiz Exp $
#

DISTNAME=	Pantomime-1.2.0pre3
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/pantomime/
COMMENT=	Objective-C mail system class library
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
