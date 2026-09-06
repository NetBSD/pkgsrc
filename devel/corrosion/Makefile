# $NetBSD: Makefile,v 1.1 2026/09/06 09:21:58 markd Exp $

DISTNAME=	corrosion-0.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=corrosion-rs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/corrosion-rs/corrosion/
COMMENT=	Corrosion, tool for integrating Rust into an existing CMake project
LICENSE=	mit

USE_TOOLS+=	gmake

.include "../../devel/cmake/build.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
