# $NetBSD: Makefile,v 1.12 2024/06/09 14:06:32 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.0.20240608
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jiixyj/}
GITHUB_PROJECT=	epoll-shim
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jiixyj/epoll-shim
COMMENT=	Small epoll implemented using kevent
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_ARGS+=	-DCMAKE_INSTALL_PKGCONFIGDIR=${PREFIX}/lib/pkgconfig

# re-defines read(2) itself
FORTIFY_SUPPORTED=	no

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

PKGCONFIG_OVERRIDE+=	epoll-shim-interpose.pc.cmakein
PKGCONFIG_OVERRIDE+=	epoll-shim.pc.cmakein

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
