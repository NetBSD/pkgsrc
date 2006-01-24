# $NetBSD: Makefile,v 1.12 2006/01/24 07:32:08 wiz Exp $
#

DISTNAME=		genecys-0.2
PKGNAME=		genecys-client-0.2
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=genecys/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.genecys.org/
COMMENT=		Client for Genecys MMORPG

DEPENDS+=		genecys-data>=0.2:../../games/genecys-data

GNU_CONFIGURE=		yes
#CONFIGURE_DIRS=		${WRKSRC}/common ${WRKSRC}/client
#BUILD_DIRS=		${WRKSRC}/common ${WRKSRC}/client
LIBS+=			-lm
CONFIGURE_ARGS+=	--disable-server --disable-metaserver --disable-utils
CONFIGURE_ARGS+=	--with-cal3d=${BUILDLINK_PREFIX.cal3d}
CONFIGURE_ARGS+=	--with-openrm=${BUILDLINK_PREFIX.OpenRM}

.include "../../graphics/cal3d/buildlink3.mk"
.include "../../graphics/OpenRM/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
