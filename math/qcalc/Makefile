# $NetBSD: Makefile,v 1.1 2023/12/31 10:40:41 pin Exp $

DISTNAME=	qcalc-0.1.3
CATEGORIES=	math
MASTER_SITES=	https://static.crates.io/crates/qcalc/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OchirErkhembayar/qcalc/
COMMENT=	Terminal GUI calculator
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
