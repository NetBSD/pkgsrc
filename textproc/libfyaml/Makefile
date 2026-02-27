# $NetBSD: Makefile,v 1.9 2026/02/27 13:47:24 adam Exp $

DISTNAME=	libfyaml-0.9.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=pantoniou/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pantoniou/libfyaml
COMMENT=	Feature-complete YAML parser and emitter
LICENSE=	mit

PKGCONFIG_OVERRIDE+=	cmake/libfyaml.pc.in

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF

.include "../../devel/cmake/build.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
