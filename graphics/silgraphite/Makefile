# $NetBSD: Makefile,v 1.6 2020/01/18 23:32:19 rillig Exp $

DISTNAME=	silgraphite-2.3.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silgraphite/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://silgraphite.sourceforge.net/
COMMENT=	Font engine for complex non-Roman writing systems

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99 c++03
WRKSRC=		${WRKDIR}/${DISTNAME}/engine

PKGCONFIG_OVERRIDE+=	silgraphite.pc.in

.include "../../mk/bsd.pkg.mk"
