# $NetBSD: Makefile,v 1.1 2024/12/25 21:11:37 pin Exp $

DISTNAME=	GemFetch-0.1.6
PKGNAME=	gemfetch-0.1.6
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/GemFetch/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sponkurtus2/GemFetch/
COMMENT=	Fetch based on a Gem
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
