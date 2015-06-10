# $NetBSD: Makefile,v 1.1 2015/06/10 01:39:33 wiedi Exp $

DISTNAME=	protobuf-c-1.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=protobuf-c/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/protobuf-c/protobuf-c
COMMENT=	Protocol Buffers implementation in C
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config aclocal autoconf automake gmake
USE_LANGUAGES=	c99 c++

PKGCONFIG_OVERRIDE+=	protobuf-c/libprotobuf-c.pc.in

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
