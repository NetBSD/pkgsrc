# $NetBSD: Makefile,v 1.1 2023/10/02 10:40:41 pin Exp $

DISTNAME=	fitme-1.1.0
CATEGORIES=	math
MASTER_SITES=	https://static.crates.io/crates/fitme/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kurtlawrence/fitme/
COMMENT=	CLI curve fitting tool
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
