# $NetBSD: Makefile,v 1.1.1.1 2004/02/10 22:02:57 garbled Exp $
#

DISTNAME=		genecys-0.1
PKGNAME=		genecys-client-0.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=genecys/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://genecys.sourceforge.net/
COMMENT=		Client for Genecys MMORPG

DEPENDS=		genecys-data>=0.1:../../games/genecys-data

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		${WRKSRC}/common ${WRKSRC}/client
BUILD_DIRS=		${WRKSRC}/common ${WRKSRC}/client
LIBS+=			-lm
CONFIG_STATUS_OVERRIDE=	${WRKSRC}/common/config.status ${WRKSRC}/client/config.status

.include "../../graphics/cal3d/buildlink3.mk"
.include "../../graphics/OpenRM/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
