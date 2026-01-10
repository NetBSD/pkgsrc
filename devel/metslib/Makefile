# $NetBSD: Makefile,v 1.4 2026/01/10 07:43:48 wiz Exp $

DISTNAME=	metslib-0.5.3
CATEGORIES=	devel
MASTER_SITES=	https://www.coin-or.org/download/source/metslib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://www.coin-or.org/download/source/metslib/
COMMENT=	metaheuristic modeling framework for tabu search
LICENSE=	gnu-gpl-v3 OR epl-v1.0

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++

PKGCONFIG_OVERRIDE+=	metslib.pc.in

.include "../../mk/bsd.pkg.mk"
