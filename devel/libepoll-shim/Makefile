# $NetBSD: Makefile,v 1.3 2021/09/21 14:44:49 ryoon Exp $

GITHUB_PROJECT=	epoll-shim
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.0.20210418
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jiixyj/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jiixyj/epoll-shim
COMMENT=	Small epoll implemented using kevent
LICENSE=	mit

ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-* DragonFly-*-*

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_TESTING=OFF

PLIST_VARS+=	eventfd timerfd
.if exists("/usr/include/sys/eventfd.h")
PLIST.eventfd=	YES
.endif
.if exists("/usr/include/sys/timerfd.h")
PLIST.timerfd=	YES
.endif

.include "../../mk/bsd.pkg.mk"
