# $NetBSD: Makefile,v 1.1.1.1 2002/04/19 14:53:35 zuntum Exp $
#

DISTNAME=	wwl-1.2
CATEGORIES=	ham
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/apps/ham/

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	calculates distance (qrb)

WRKSRC=		${WRKDIR}/wwl
NO_CONFIGURE=	yes
NO_PATCH=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wwl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
