# $NetBSD: Makefile,v 1.1.1.1 2002/09/29 03:48:08 rh Exp $
#

DISTNAME=	GNUMail-1.0.3
WRKSRC=		${WRKDIR}/GNUMail
CATEGORIES=	mail gnustep
MASTER_SITES=	http://extrovert.screwdriver.net/~extra/cgi-bin/
DISTFILES=	mirror.cgi?file=${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.collaboration-world.com/gnumail/
COMMENT=	GNUstep clone of NeXT\'s Mail.app application

NO_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES
MAKEFILE=	GNUmakefile
#MAKE_ENV+=	ADDITIONAL_CPPFLAGS=-DMKDIR

.include "../../mail/Pantomime/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
