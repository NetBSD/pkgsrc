# $NetBSD: Makefile,v 1.1 2026/07/22 16:14:38 ryoon Exp $

DISTNAME=	pdfrip-3.0.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=mufeedvh/}
GITHUB_PROJECT=	pdfrip
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mufeedvh/pdfrip/
COMMENT=	Multi-threaded PDF password cracking utility
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES=	c

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
