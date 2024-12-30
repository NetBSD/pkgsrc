# $NetBSD: Makefile,v 1.1 2024/12/30 21:53:47 pin Exp $

DISTNAME=	clicsv-1.0.4
CATEGORIES=	textproc
MASTER_SITES=	https://static.crates.io/crates/clicsv/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sudo-shaka/clicsv/
COMMENT=	Command line spreadsheet editor
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
