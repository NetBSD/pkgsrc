# $NetBSD: Makefile,v 1.1.1.1 2004/04/16 19:34:06 xtraeme Exp $
#

DISTNAME=	powermanga
PKGNAME=	${DISTNAME}-0.78
CATEGORIES=	games
MASTER_SITES=	http://www.tlk.fr/lesjeux/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.tlk.fr/lesjeux/
COMMENT=	SHORT_DESCRIPTION_OF_THE_PACKAGE

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes
WRKSRC=		${WRKDIR}/powermanga-0.78

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
