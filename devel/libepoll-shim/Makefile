# $NetBSD: Makefile,v 1.2 2021/05/03 17:20:24 jdolecek Exp $

GITHUB_PROJECT=	epoll-shim
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.0.20210418
PKGNAME=	lib${DISTNAME}
PKGREVISION=	# empty
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

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
