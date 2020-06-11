# $NetBSD: Makefile,v 1.1 2020/06/11 13:45:36 ryoon Exp $

DISTNAME=	libsignal-protocol-c-2.3.3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=signalapp/}
GITHUB_PROJECT=	libsignal-protocol-c
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/signalapp/libsignal-protocol-c/
COMMENT=	Signal Protocol C Library
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=true

PKGCONFIG_OVERRIDE+=	src/libsignal-protocol-c.pc.in

.include "../../mk/bsd.pkg.mk"
