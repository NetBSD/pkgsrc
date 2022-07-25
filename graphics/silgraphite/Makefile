# $NetBSD: Makefile,v 1.8 2022/07/25 11:12:25 wiz Exp $

DISTNAME=	silgraphite-2.3.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silgraphite/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://silgraphite.sourceforge.net/
COMMENT=	Font engine for complex non-Roman writing systems

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c99 c++03
WRKSRC=		${WRKDIR}/${DISTNAME}/engine

PKGCONFIG_OVERRIDE+=	silgraphite.pc.in

.include "../../mk/bsd.pkg.mk"
