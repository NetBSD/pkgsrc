# $NetBSD: Makefile,v 1.3 2022/07/25 11:12:21 wiz Exp $

DISTNAME=	ETL-0.04.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=synfig/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://synfig.org/
COMMENT=	C++ template library for synfig

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	ETL.pc.in

.include "../../mk/bsd.pkg.mk"
