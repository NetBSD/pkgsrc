# $NetBSD: Makefile,v 1.1 2026/08/27 10:58:45 drixter Exp $

DISTNAME=	leaves-0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=patonw/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/patonw/leaves/
COMMENT=	Text-mode disk usage visualization utility
LICENSE=	mpl-2.0

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
