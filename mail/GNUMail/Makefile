# $NetBSD: Makefile,v 1.19 2006/02/05 23:09:53 joerg Exp $
#

DISTNAME=	GNUMail-1.1.2
PKGREVISION=	5
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/gnumail/
COMMENT=	GNUstep clone of NeXT's Mail.app application

WRKSRC=		${WRKDIR}/GNUMail
NO_CONFIGURE=	yes

post-extract:
	${RM} -r ${WRKSRC}/*/*/CVS

.include "../../mail/Pantomime/buildlink3.mk"
.include "../../misc/Addresses/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
