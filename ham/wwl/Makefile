# $NetBSD: Makefile,v 1.6 2005/06/16 06:57:59 jlam Exp $
#

DISTNAME=	wwl-1.2
CATEGORIES=	ham
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/apps/ham/

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	Calculates distance (qrb)

WRKSRC=		${WRKDIR}/wwl
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wwl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
