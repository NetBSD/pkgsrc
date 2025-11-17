# $NetBSD: Makefile,v 1.4 2025/11/17 11:00:16 wiz Exp $

DISTNAME=	aften-0.0.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aften/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://aften.sourceforge.net/
COMMENT=	ATSC A/52 / AC-3 / Dolby Digital audio encoder
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBINDINGS_CXX=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5
CMAKE_CONFIGURE_ARGS+=	-DSHARED=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
