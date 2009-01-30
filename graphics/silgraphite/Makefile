# $NetBSD: Makefile,v 1.1.1.1.2.1 2009/01/30 12:38:02 tron Exp $

DISTNAME=	silgraphite-2.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silgraphite/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://silgraphite.sourceforge.net/
COMMENT=	Font engine for complex non-Roman writing systems

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99 c++
WRKSRC=		${WRKDIR}/${DISTNAME}/engine

PKGCONFIG_OVERRIDE+=	silgraphite.pc.in

.include "../../mk/bsd.pkg.mk"
