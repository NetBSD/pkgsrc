# $NetBSD: Makefile,v 1.14 2023/11/12 13:22:18 wiz Exp $

DISTNAME=	silgraphite-2.3.1
PKGNAME=	${DISTNAME:S/silgraphite/silgraphite-xft/}
PKGREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silgraphite/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://silgraphite.sourceforge.net/
COMMENT=	Xft wrapper for SIL Graphite

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${DISTNAME}/wrappers/xft

INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../graphics/silgraphite/buildlink3.mk"
.include "../../graphics/silgraphite-ft/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/silgraphite-xft.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
