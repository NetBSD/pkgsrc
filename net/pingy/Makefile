# $NetBSD: Makefile,v 1.2 2026/06/02 11:08:04 pin Exp $

DISTNAME=	pingy-0.1.10
CATEGORIES=	net
MASTER_SITES=	https://static.crates.io/crates/pingy/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trinhminhtriet/pingy/
COMMENT=	Fast, concurrent ping tool with real-time updates & visual charts
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
