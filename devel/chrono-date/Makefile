# $NetBSD: Makefile,v 1.1 2026/04/14 12:46:17 kikadf Exp $

DISTNAME=	chrono-date-3.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=HowardHinnant/}
GITHUB_PROJECT=	date
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://howardhinnant.github.io/date/date.html
COMMENT=	Date and time library based on the C++11/14/17 <chrono> header
LICENSE=	mit

USE_LANGUAGES=		c c++
WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TZ_LIB=ON

SUBST_CLASSES+=		pc
SUBST_STAGE.pc=		pre-configure
SUBST_MESSAGE.pc=	Set pkg-config file
SUBST_FILES.pc=		date.pc.in
SUBST_SED.pc+=		-e 's|@VERSION@|${PKGVERSION_NOREV}|g'

.include "../../devel/cmake/build.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
