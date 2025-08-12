# $NetBSD: Makefile,v 1.3 2025/08/12 07:56:23 adam Exp $

DISTNAME=	aften-0.0.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aften/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aften.sourceforge.net/
COMMENT=	ATSC A/52 / AC-3 / Dolby Digital audio encoder
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBINDINGS_CXX=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5
CMAKE_CONFIGURE_ARGS+=	-DSHARED=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
