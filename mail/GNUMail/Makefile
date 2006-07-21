# $NetBSD: Makefile,v 1.22 2006/07/21 05:33:01 rillig Exp $
#

DISTNAME=	GNUMail-1.1.2
PKGREVISION=	6
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/gnumail/
COMMENT=	GNUstep clone of NeXT's Mail.app application

USE_LANGUAGES=	c objc

WRKSRC=		${WRKDIR}/GNUMail
NO_CONFIGURE=	yes

post-extract:
	${RM} -r ${WRKSRC}/*/*/CVS

.include "../../mail/Pantomime/buildlink3.mk"
.include "../../misc/Addresses/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
