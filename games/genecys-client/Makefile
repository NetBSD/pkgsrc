# $NetBSD: Makefile,v 1.10 2005/12/26 23:39:32 schmonz Exp $
#

DISTNAME=		genecys-0.2
PKGNAME=		genecys-client-0.2
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=genecys/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.genecys.org/
COMMENT=		Client for Genecys MMORPG

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

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
