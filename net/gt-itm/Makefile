# $NetBSD: Makefile,v 1.3 2012/10/23 17:18:25 asau Exp $

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
	${INSTALL_PROGRAM} ${WRKDIR}/bin/* ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/docs/* ${DESTDIR}${PREFIX}/share/doc/gt-itm

.include "../../mk/bsd.pkg.mk"
