# $NetBSD: Makefile,v 1.5 2016/11/01 15:22:26 wiz Exp $

DISTNAME=	glog-0.3.4
PKGNAME=	google-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	glog
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	https://github.com/google/glog/
COMMENT=	Application Level Logging library for C++
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libglog.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=		-lexecinfo
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11
.endif

.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
