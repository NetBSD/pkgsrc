# $NetBSD: Makefile,v 1.3 2026/01/14 12:57:31 wiz Exp $

DISTNAME=	libomemo-c-0.5.1
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=dino/}
GITHUB_PROJECT=	libomemo-c
GITHUB_RELEASE=	v0.5.1

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/dino/libomemo-c/
COMMENT=	OMEMO library (asynchronous ratcheting forward-secrecy)
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/libomemo-c.pc.in

# Upstream documents cmake but meson works better.
# https://github.com/dino/libomemo-c/issues/13
.include "../../devel/meson/build.mk"

.include "../../devel/check/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
# TEST_DEPENDS, perhaps
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
