# $NetBSD: Makefile,v 1.9 2022/08/07 23:29:49 tnn Exp $

DISTNAME=	${GITHUB_PROJECT}-0.0.20210418
PKGNAME=	lib${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jiixyj/}
GITHUB_PROJECT=	epoll-shim
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jiixyj/epoll-shim
COMMENT=	Small epoll implemented using kevent
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_ARGS+=	-DCMAKE_INSTALL_PKGCONFIGDIR=${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.prefs.mk"

.if !defined(OPSYS_HAS_KQUEUE)
PKG_SKIP_REASON+=	"Requires a kqueue implementation"
.endif

PLIST_VARS+=	eventfd timerfd
.if !defined(OPSYS_HAS_EVENTFD)
PLIST.eventfd=	YES
.endif
.if !defined(OPSYS_HAS_TIMERFD)
PLIST.timerfd=	YES
.endif

PKGCONFIG_OVERRIDE+=	epoll-shim.pc.cmakein

.include "../../mk/bsd.pkg.mk"
