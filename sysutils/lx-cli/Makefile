# $NetBSD: Makefile,v 1.3 2026/10/24 17:19:01 pin Exp $

DISTNAME=	lx-cli-0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/lx-cli/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JackDerksen/lx-cli/
COMMENT=	Nicer way to list your files
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
