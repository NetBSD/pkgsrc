# $NetBSD: Makefile,v 1.3 2003/03/29 12:41:22 jmmv Exp $
#

DISTNAME=	wwl-1.2
WRKSRC=		${WRKDIR}/wwl
CATEGORIES=	ham
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/apps/ham/

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	calculates distance (qrb)

NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wwl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
