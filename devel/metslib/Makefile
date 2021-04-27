# $NetBSD: Makefile,v 1.1 2021/04/27 22:58:40 thor Exp $

DISTNAME=	metslib-0.5.3
CATEGORIES=	devel
MASTER_SITES=	http://www.coin-or.org/download/source/metslib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	http://www.coin-or.org/download/source/metslib/
COMMENT=	metaheuristic modeling framework for tabu search
LICENSE=	gnu-gpl-v3 OR epl-v1.0

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

PKGCONFIG_OVERRIDE+=	metslib.pc.in

.include "../../mk/bsd.pkg.mk"
