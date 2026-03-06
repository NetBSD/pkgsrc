# $NetBSD: Makefile,v 1.11 2026/03/06 11:20:03 pin Exp $

DISTNAME=	piratebay-0.2.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsirysndr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tsirysndr/piratebay/
COMMENT=	CLI tool to search for torrents on piratebay
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
