# $NetBSD: Makefile,v 1.8 2025/04/03 21:08:56 pin Exp $

DISTNAME=	piratebay-0.1.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsirysndr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tsirysndr/piratebay/
COMMENT=	CLI tool to search for torrents on piratebay
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
NOT_FOR_PLATFORM+=	*-*-i386

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
