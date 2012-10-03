# $NetBSD: Makefile,v 1.8 2012/10/03 13:01:46 asau Exp $
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
	${INSTALL_PROGRAM} ${WRKSRC}/wwl ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
