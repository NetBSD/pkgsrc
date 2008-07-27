# $NetBSD: Makefile,v 1.28 2008/07/27 17:06:57 joerg Exp $
#

DISTNAME=	GNUMail-1.1.2
PKGREVISION=	9
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/gnumail/
COMMENT=	GNUstep clone of NeXT's Mail.app application

USE_LANGUAGES=	objc

WRKSRC=		${WRKDIR}/GNUMail
NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${PREFIX}/share/GNUstep/Local/

post-extract:
	${RM} -r ${WRKSRC}/*/*/CVS

.include "../../mail/Pantomime/buildlink3.mk"
.include "../../misc/Addresses/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
