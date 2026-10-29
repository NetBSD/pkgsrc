# $NetBSD: Makefile,v 1.1 2026/10/29 14:59:53 drixter Exp $

DISTNAME=	cloudflare-speed-cli-1.0.11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=kavehtehrani/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/kavehtehrani/cloudflare-speed-cli/
COMMENT=	Network speed test tool using Cloudflare's speed test service
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
