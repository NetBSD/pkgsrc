# $NetBSD: Makefile,v 1.2 2013/02/26 10:24:50 joerg Exp $
#

DISTNAME=	glog-0.3.3
PKGNAME=	google-${DISTNAME}
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

.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/gmock/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
