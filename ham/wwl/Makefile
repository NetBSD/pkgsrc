# $NetBSD: Makefile,v 1.4 2003/07/21 16:52:08 martti Exp $
#

DISTNAME=	wwl-1.2
WRKSRC=		${WRKDIR}/wwl
CATEGORIES=	ham
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/apps/ham/

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	Calculates distance (qrb)

NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wwl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
