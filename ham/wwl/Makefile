# $NetBSD: Makefile,v 1.5 2004/01/20 12:18:36 agc Exp $
#

DISTNAME=	wwl-1.2
CATEGORIES=	ham
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/apps/ham/

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	Calculates distance (qrb)

WRKSRC=		${WRKDIR}/wwl
NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wwl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
