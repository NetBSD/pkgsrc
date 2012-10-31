# $NetBSD: Makefile,v 1.2 2012/10/31 11:16:30 asau Exp $
#

DISTNAME=	ETL-0.04.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=synfig/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://synfig.org/
COMMENT=	C++ template library for synfig

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	ETL.pc.in

.include "../../mk/bsd.pkg.mk"
