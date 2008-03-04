# $NetBSD: Makefile,v 1.7 2008/03/04 15:51:59 jlam Exp $
#

DISTNAME=	wwl-1.2
CATEGORIES=	ham
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/apps/ham/

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	Calculates distance (qrb)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/wwl
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wwl ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
