# $NetBSD: Makefile,v 1.7 2022/07/25 11:12:22 wiz Exp $

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

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_TESTING=OFF

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

.include "../../mk/bsd.pkg.mk"
