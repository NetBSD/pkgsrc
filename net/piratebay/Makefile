# $NetBSD: Makefile,v 1.7 2025/04/02 11:01:55 pin Exp $

DISTNAME=	piratebay-0.1.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsirysndr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/tsirysndr/piratebay/
COMMENT=	CLI tool to search for torrents on piratebay
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
NOT_FOR_PLATFORM+=	*-*-i386

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
