# $NetBSD: Makefile,v 1.5 2018/07/18 00:06:19 joerg Exp $

DISTNAME=	silgraphite-2.3.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silgraphite/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://silgraphite.sourceforge.net/
COMMENT=	Font engine for complex non-Roman writing systems

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99 c++03
WRKSRC=		${WRKDIR}/${DISTNAME}/engine

PKGCONFIG_OVERRIDE+=	silgraphite.pc.in

.include "../../mk/bsd.pkg.mk"
