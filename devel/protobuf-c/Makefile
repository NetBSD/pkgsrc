# $NetBSD: Makefile,v 1.7 2020/10/01 20:35:23 gdt Exp $

DISTNAME=	protobuf-c-1.3.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=protobuf-c/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/protobuf-c/protobuf-c
COMMENT=	Protocol Buffers implementation in C
LICENSE=	modified-bsd

USE_LANGUAGES=		c99 c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	protobuf-c/libprotobuf-c.pc.in
TEST_TARGET=		check

.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
