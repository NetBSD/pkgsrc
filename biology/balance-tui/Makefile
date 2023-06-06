# $NetBSD: Makefile,v 1.3 2023/06/06 19:25:14 pin Exp $

DISTNAME=	balance-tui-0.1.2
CATEGORIES=	biology
MASTER_SITES=	https://static.crates.io/crates/balance-tui/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BeaconBrigade/balance-tui/
COMMENT=	Balance chemical equations from the CLI
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
