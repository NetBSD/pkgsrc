# $NetBSD: Makefile,v 1.3 2011/10/10 21:42:13 minskim Exp $

DISTNAME=	silgraphite-2.3.1
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
