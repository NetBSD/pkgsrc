# $NetBSD: Makefile,v 1.4 2013/07/18 12:01:29 joerg Exp $
#

DISTNAME=	glog-0.3.3
PKGNAME=	google-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://google-glog.googlecode.com/files/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://code.google.com/p/google-glog/
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
.include "../../devel/gmock/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
