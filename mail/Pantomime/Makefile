# $NetBSD: Makefile,v 1.4 2003/07/17 21:45:40 grant Exp $
#

DISTNAME=	Pantomime-1.0.5
PKGREVISION=	2
WRKSRC=		${WRKDIR}/Pantomime
CATEGORIES=	mail gnustep
MASTER_SITES=	http://extrovert.screwdriver.net/~extra/cgi-bin/
DISTFILES=	mirror.cgi?file=${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/pantomime/
COMMENT=	Objective-C mail system class library

NO_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES
MAKEFILE=	GNUmakefile
MAKE_ENV+=	ADDITIONAL_CPPFLAGS=-DMKDIR

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
