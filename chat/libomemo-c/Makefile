# $NetBSD: Makefile,v 1.6 2026/08/26 10:19:04 adam Exp $

DISTNAME=	libomemo-c-0.5.1
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=dino/}
GITHUB_PROJECT=	libomemo-c
GITHUB_RELEASE=	v0.5.1

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/dino/libomemo-c/
COMMENT=	OMEMO library (asynchronous ratcheting forward-secrecy)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/libomemo-c.pc.in

# Upstream README.md says that the build system is cmake.  However
# that has multiple problems, and building with meson seems to work.
#   https://github.com/dino/libomemo-c/issues/13

LIBOMEMO_BUILD=	meson

.if !empty(LIBOMEMO_BUILD:Mmeson)
.  include "../../devel/meson/build.mk"
.else
# The cmake builds tries to use a c++ compiler and exits when that fails.
# It fails (correctly) if USE_LANGUAGES does not contain c++
USE_LANGUAGES+=		c++
.  include "../../devel/cmake/build.mk"
.endif

.include "../../devel/check/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
# TEST_DEPENDS, perhaps
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
