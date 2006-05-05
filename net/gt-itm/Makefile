# $NetBSD: Makefile,v 1.1.1.1 2006/05/05 23:14:43 minskim Exp $

DISTNAME=	gt-itm
PKGNAME=	gt-itm-0pre19961004
CATEGORIES=	net
MASTER_SITES=	http://www-static.cc.gatech.edu/projects/gtitm/gt-itm/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www-static.cc.gatech.edu/projects/gtitm/
COMMENT=	GT Internetwork Topology Models

USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/src

INSTALLATION_DIRS+=	bin share/doc/gt-itm

.include "../../devel/sgb/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/* ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/docs/* ${PREFIX}/share/doc/gt-itm

.include "../../mk/bsd.pkg.mk"
