# $NetBSD: Makefile,v 1.10 2022/03/27 13:41:06 tnn Exp $

DISTNAME=	glog-0.4.0
PKGNAME=	google-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	glog
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/glog/
COMMENT=	Application Level Logging library for C++
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake pkg-config
USE_LANGUAGES=	c c++11

PKGCONFIG_OVERRIDE+=	libglog.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-pie

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LIBS+=		-lexecinfo
.endif

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
