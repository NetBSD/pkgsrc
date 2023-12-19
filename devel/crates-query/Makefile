# $NetBSD: Makefile,v 1.1 2023/12/19 09:48:20 pin Exp $

DISTNAME=	crates-query-0.1.1
CATEGORIES=	devel
MASTER_SITES=	https://static.crates.io/crates/crates-query/
EXTRACT_SUFX=	.crate

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/michaelciraci/Crates-Query/
COMMENT=	Query crates.io from command line
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
